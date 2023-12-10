#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
from sonar.msg import ThreeSonarDepth
from std_msgs.msg import Header
from geometry_msgs.msg import Vector3Stamped
from random import uniform
from std_msgs.msg import Float64
import pandas as pd
import numpy as np
from glob import glob
import rosbag
from message_filters import ApproximateTimeSynchronizer, Subscriber
import subprocess
import time

time=0
i=0

paths=sorted(glob("/home/*/Desktop/dataset4*.bag"))

synchronized_data=[]
def callback(data1, data2,data3):
    # Your synchronization logic here
    # data1 is the message from topic1
    # data2 is the message from topic2
    timestamp = data1.header.stamp
    #rospy.loginfo(data1)
    # Write the synchronized messages to the new rosbag file
    synchronized_data.append({
        'Timestamp': timestamp,
        'Pose_X': data1.vector.x,
        'Pose_Y': data1.vector.y,
        'Pose_Z': data1.vector.z,
        'Sonar_Distance_1': data3.vector.x,
        'Sonar_Distance_2': data3.vector.y,
        'Sonar_Distance_3': data3.vector.z,
        'IMU_Linear_Acc_X': data2.vector.x,
        'IMU_Linear_Acc_Y': data2.vector.y,
        'IMU_Linear_Acc_Z': data2.vector.z,
    })
    synchronized_df = pd.DataFrame(synchronized_data)
    synchronized_df.to_csv(output_csv_file,index=False)

synchronized_data2=[]
def callback2(data1, data2):
    # Your synchronization logic here
    # data1 is the message from topic1
    # data2 is the message from topic2
    timestamp = data1.header.stamp
    #rospy.loginfo(data1)
    # Write the synchronized messages to the new rosbag file
    synchronized_data2.append({
        'Timestamp': timestamp,
        'IMU_Raw_x': data1.linear_acceleration.x,
        'IMU_Raw_y': data1.linear_acceleration.y,
        'IMU_Raw_z': data1.linear_acceleration.z,
        'IMU_Linear_Acc_X': data2.vector.x,
        'IMU_Linear_Acc_Y': data2.vector.y,
        'IMU_Linear_Acc_Z': data2.vector.z,
    })
    '''
    synchronized_data2.append({
        'Timestamp': timestamp,
        'IMU_Raw_x': data1.linear_acceleration.x,
        'IMU_Raw_y': data1.linear_acceleration.y,
        'IMU_Raw_z': data1.linear_acceleration.z,
    })'''
    synchronized_df2 = pd.DataFrame(synchronized_data2)
    synchronized_df2.to_csv(output_csv_file2,index=False)


if __name__ == '__main__':
    rospy.init_node('rosbag_time_sync')

    # Specify the topics you want to synchronize
    topic1 = 'Pose'
    topic2 = 'SONAR_raw'
    topic3 = 'IMU_raw'
    topic4 = 'IMU_filtered'
    topic5 = 'SONAR_filtered'

    i=0
    # Open the rosbag file
    bag_file = paths[i]  # Change to your rosbag file name
    output_bag_file = paths[i].split(".")[0]+'_sync.bag'  # Change to your output rosbag file name

    # Create a TimeSynchronizer
    output_csv_file = paths[i].split(".")[0] + '_sync.csv'
    output_csv_file2 = paths[i].split(".")[0] + '_sync_imu.csv'
    rospy.loginfo(output_csv_file2)
    # Create subscribers for each topic
    sub1 = Subscriber(topic1, Vector3Stamped)  # Adjust the message type according to your topics
    sub2 = Subscriber(topic2, ThreeSonarDepth)  # Adjust the message type according to your topics
    sub3 = Subscriber(topic3, Imu)  # Adjust the message type according to your topics
    sub4 = Subscriber(topic4, Vector3Stamped)  # Adjust the message type according to your topics
    sub5 = Subscriber(topic5, Vector3Stamped)  # Adjust the message type according to your topics
    ts = ApproximateTimeSynchronizer([sub1,sub4,sub5], 10, slop=2000)  # 100 is the queue size, adjust as needed
    ts2 = ApproximateTimeSynchronizer([sub3,sub4], 10, slop=20)  # 100 is the queue size, adjust as needed
    # Start rosbag play subprocess

    # Open the output rosbag file for writing
    #output_bag = rosbag.Bag(output_bag_file, 'w')

    # Set the callback function
    ts.registerCallback(callback)
    ts2.registerCallback(callback2)
    
    # Keep the script running
    rospy.spin()

    # Close the output rosbag
    #output_bag.close()
    rospy.loginfo("Done")

