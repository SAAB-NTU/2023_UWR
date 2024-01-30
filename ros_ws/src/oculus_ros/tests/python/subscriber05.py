#!/usr/bin/python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
from glob import glob

class SonarListener:
    def __init__(self):
        self.time_duration = 1
        self.start_time = rospy.Time.now().secs

        self.cv_bridge = CvBridge()

        self.h, self.w = (1200, 260)
        self.r = (2 * self.h - 1)
        self.top = False
        self.angle = 130
        self.angle_v = 20
        self.k = 2

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
        polar_raised = polar_img_resized
        rospy.loginfo(data.header.stamp)
        #rospy.loginfo(polar_img.shape)

        polar_raised = np.rot90(polar_raised, 2)
        im_fan = np.ones((self.r, self.r), dtype=np.uint8)

        for i in range(self.k*self.w):
            im_fan[(self.rows_list[i], self.cols_list[i])] = polar_raised[:, i//self.k]
        #rospy.loginfo(self.rows_list)
        #im_fan[self.rows_list, self.cols_list] = polar_raised[:, np.arange(0, self.k * self.w, self.k)].ravel()
        im_fan = im_fan[self.r//2:, :]
        im_out = np.flip(im_fan, axis=0)

        if (rospy.Time.now().secs - self.start_time >= self.time_duration):
            rospy.loginfo("saving")
            cv2.imwrite("/home/uwr/Desktop/fls_images_cart/" + str(data.header.stamp) + ".png", im_out)
            cv2.imwrite("/home/uwr/Desktop/fls_images_polar/" + str(data.header.stamp) + ".png", polar_img)
            self.start_time = rospy.Time.now().secs

        image_msg = self.cv_bridge.cv2_to_imgmsg(im_out, encoding="8UC1")
        image_msg.header.stamp = rospy.Time.now()
        self.fls_fan_pub.publish(image_msg)

if __name__ == '__main__':
    rospy.init_node('sonar_listener', anonymous=True)
    sonar_listener = SonarListener()
    rospy.spin()
