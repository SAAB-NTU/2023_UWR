#! /usr/bin/python3

# import roslibpy
# client = roslibpy.Ros(host='localhost', port=11311)
# client.run()

import rospy
import oculus_sonar.msg as oculus_msg
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
from glob import glob
cv_bridge = CvBridge()

h, w = (591,260)
r = 2 * h - 1
top = False
angle = 130
angle_v=20
k = 100


def callback(data):
    data.data = []
    #print(data, flush=True)
def callback_fan(data):
    img_no=len(glob("/home/uwr/Desktop/fls_images_cart/*"))+1
    polar_img = cv_bridge.imgmsg_to_cv2(data, "bgr8")
    polar_img=cv2.cvtColor(polar_img,cv2.COLOR_BGR2GRAY)
    #polar_normal=1-(polar_img-np.min(polar_img))/(np.max(polar_img)-np.min(polar_img))
    #polar_raised=polar_normal*255
    polar_raised=cv2.resize(polar_img,(w,h))
    rospy.loginfo(polar_img.shape)
    
    polar_raised=np.rot90(polar_raised,2)
    im_fan = np.ones((r, r), dtype=np.uint8)
    idx = np.arange(h) if top else np.arange(h)[::-1]
    alpha = np.radians(np.linspace(-angle/2, angle/2, k*w))
    for i in range(k*w):  
        rows = np.int32(np.ceil(np.cos(alpha[i]) * idx)) + r // 2
        cols = np.int32(np.ceil(np.sin(alpha[i]) * idx)) + r // 2
        im_fan[(rows, cols)] = polar_raised[:, i//k]
    im_fan = im_fan[r//2:, :]
    im_out = np.flip(im_fan, axis=0)
    cv2.imwrite("/home/uwr/Desktop/fls_images/"+f"{img_no:05d}"+".png",im_out)
    image_msg = cv_bridge.cv2_to_imgmsg(im_out, encoding="8UC1")

        # Set the timestamp of the message (optional)
    image_msg.header.stamp = rospy.Time.now()
    fls_fan_pub.publish(image_msg)

rospy.init_node('sonar_listener', anonymous=True)
fls_fan_pub = rospy.Publisher('/fls_fan_img', Image, queue_size=1)
#rospy.Subscriber('/ping', oculus_msg.OculusPing, callback)
rospy.Subscriber("/oculus_sonar/ping_image", Image, callback_fan)


rospy.spin()

