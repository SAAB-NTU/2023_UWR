#! /usr/bin/python3
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
from glob import glob
from scipy.ndimage import map_coordinates as mc

class SonarListener:
    def __init__(self):
        self.time_duration = 2
        self.start_time = rospy.Time.now().secs

        self.cv_bridge = CvBridge()

        self.h, self.w = (591, 260)
        self.r = (2 * self.h - 1)
        self.top = False
        self.angle = 130
        self.angle_v = 20
        self.k = 1

        self.rows_list = []
        self.cols_list = []

        alpha = np.radians(np.linspace(-self.angle/2, self.angle/2, self.k*self.w))
        idx = np.arange(self.h) if self.top else np.arange(self.h)[::-1]

        for i in range(self.k*self.w):
            self.rows_list.append(np.int32(np.ceil(np.cos(alpha[i]) * idx)+ self.r // 2) )
            self.cols_list.append(np.int32(np.ceil(np.sin(alpha[i]) * idx)+ self.r // 2) )

        self.fls_fan_pub = rospy.Publisher('/fls_fan_img', Image, queue_size=1)
        rospy.Subscriber("/oculus_sonar/ping_image", Image, self.callback_fan)

    def callback_fan(self, data):
        polar_img = self.cv_bridge.imgmsg_to_cv2(data, "mono8")
        polar_img_resized = cv2.resize(polar_img, (self.w, self.h))
        img_no = len(glob("/home/uwr/Desktop/fls_images_cart/*")) + 1
        polar_raised = np.rot90(polar_img_resized, 2)

        im_fan = np.ones((self.r, self.r), dtype=np.uint8)

        rows_indices = np.array(self.rows_list)
        cols_indices = np.array(self.cols_list)

        # Ensure indices are within bounds
        row_coordinates = np.clip(rows_indices, 0, polar_raised.shape[0] - 1).astype(np.float32)
        col_coordinates = np.clip(cols_indices, 0, polar_raised.shape[1] - 1).astype(np.float32)

        # Create grid of coordinates
        row_grid, col_grid = np.meshgrid(np.arange(self.r), np.arange(self.r), indexing='ij')
        map_coordinates = np.column_stack((row_coordinates, col_coordinates))

        # Perform remapping using scipy
        remapped_values = mc(polar_raised, map_coordinates.T, order=1, mode='nearest')

        # Reshape the remapped values to the shape of im_fan
        remapped_values = remapped_values.reshape(self.r, self.r)

        # Assign remapped values to im_fan
        im_fan[rows_indices, cols_indices] = remapped_values[rows_indices, cols_indices]

        im_fan = im_fan[self.r//2:, :]
        im_out = np.flip(im_fan, axis=0)

        if (rospy.Time.now().secs - self.start_time >= self.time_duration):
            rospy.loginfo("saving")
            cv2.imwrite(f"/home/uwr/Desktop/fls_images_cart/{img_no:05d}.png", im_out)
            cv2.imwrite(f"/home/uwr/Desktop/fls_images_polar/{img_no:05d}.png", polar_img)
            self.start_time = rospy.Time.now().secs

        image_msg = self.cv_bridge.cv2_to_imgmsg(im_out, encoding="8UC1")
        image_msg.header.stamp = rospy.Time.now()
        self.fls_fan_pub.publish(image_msg)

if __name__ == '__main__':
    rospy.init_node('sonar_listener', anonymous=True)
    sonar_listener = SonarListener()
    rospy.spin()
