#!/usr/bin/env python3
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image,CompressedImage
import numpy as np
import cv2

cv_bridge=CvBridge()
def callback_FLS(data):
    cv_image = cv_bridge.compressed_imgmsg_to_cv2(data, "bgr8")
    cv2.imwrite("/home/saab/Desktop/img.png",cv_image)
def callback_RGB(data):
    cv_image = cv_bridge.imgmsg_to_cv2(data, "bgr8")
    cv2.imwrite("/home/saab/Desktop/img2.png",cv_image)
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('FLS_image', anonymous=True)

    rospy.Subscriber("/marus_boat/sonar/compressed", CompressedImage, callback_FLS)
    rospy.Subscriber("/marus_boat/camera_bow", Image, callback_RGB)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()