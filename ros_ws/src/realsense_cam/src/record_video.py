#!/usr/bin/env python3
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import CompressedImage
import numpy as np
import cv2
import time

cv_bridge = CvBridge()
image_list = []

def callback_video(data):
    cv_image = cv_bridge.compressed_imgmsg_to_cv2(data, "bgr8")
    image_list.append(cv_image)

def save_images_as_video():
    if not image_list:
        print("No images to save.")
        return

    # Get the height and width of the first image to create the video writer
    height, width, _ = image_list[0].shape
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # Use mp4v codec for mp4 format
    video_writer = cv2.VideoWriter('/home/saab/Desktop/output_video.mp4', fourcc, 30.0, (width, height))

    start_time = time.time()
    while True:
        if not image_list:
            break

        frame = image_list.pop(0)
        video_writer.write(frame)

        current_time = time.time()
        elapsed_time = current_time - start_time

        if elapsed_time >= 60:
            break

    video_writer.release()
    print("Video saved.")

def listener():
    rospy.init_node('video_capture', anonymous=True)
    rospy.Subscriber("/camera/color/image_raw/compressed", CompressedImage, callback_video)
    rospy.on_shutdown(save_images_as_video)  # Save the video when the node is shut down

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
