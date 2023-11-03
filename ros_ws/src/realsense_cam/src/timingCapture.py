#!/usr/bin/env python3

import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import CompressedImage
import cv2
import time
from glob import glob
import os

cv_bridge = CvBridge()
main_path="/home/sunrise/Desktop/Nov02_exp"

class timingCapture:
    def __init__(self):
        rospy.init_node("timingCapture", anonymous = True)
        self.image_sub = rospy.Subscriber("/camera/color/image_raw/compressed", CompressedImage, self.image_callback)
        self.image = None
        print("Node has been successfully created!")
    
    def image_callback(self, data):
        self.image = data
        
    def timed_saving(self, path = main_path):
        try:
            cv_image = cv_bridge.compressed_imgmsg_to_cv2(self.image,"bgr8")
            num=len(glob(path+"/*"))
            cv2.imwrite(path+"/"+f"{num+1:04d}"+".png",cv_image)
            string = f"{num+1:04d}"+".png" + " has been successfully saved"
            rospy.loginfo(string)          
        except rospy.ServiceException as e:
            print("Service call failed: %s"%e)

def testing():
    print("Are we in the testing node?")
    start_time = time.time()
    while True:       
        #print(rospy.Time.now())
        print(time.time()-start_time)   
            
            
if __name__ == "__main__":
    time_duration = 2
    timing_Capture = timingCapture()
    start_time = rospy.Time.now().secs
    print(start_time)
    while not rospy.is_shutdown():
        if (rospy.Time.now().secs - start_time >= time_duration):
            timing_Capture.timed_saving()
            start_time = rospy.Time.now().secs
            