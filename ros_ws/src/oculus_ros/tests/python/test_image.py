#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

def publish_image_from_file():
    # Initialize the ROS node
    rospy.init_node('image_publisher', anonymous=True)
    
    # Create a publisher for the 'ping_image' topic
    image_pub = rospy.Publisher('/oculus_sonar/ping_image', Image, queue_size=1)
    
    # Initialize CvBridge for image conversion
    bridge = CvBridge()

    # Load the image from file (change the file path accordingly)
    image_path = '/home/uwr/Desktop/00001.png'
    image = cv2.imread(image_path)

    # Check if the image was loaded successfully
    if image is None:
        rospy.logerr("Failed to load the image from file")
        return

    try:
        # Create an Image message
        image_msg = bridge.cv2_to_imgmsg(image, encoding="bgr8")

        # Set the timestamp of the message (optional)
        image_msg.header.stamp = rospy.Time.now()

        # Publish the image message
        image_pub.publish(image_msg)

        rospy.loginfo("Published image to 'ping_image' topic")

  

    except rospy.ROSInterruptException:
        pass
    

if __name__ == '__main__':
    while(not rospy.is_shutdown()):
        publish_image_from_file()
    

