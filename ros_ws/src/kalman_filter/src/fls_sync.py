#!/usr/bin/env python3

import rospy
from sonar.msg import ThreeSonarDepth
import pandas as pd
import numpy as np
import rosbag

def sonar_data_publisher(sonar_pub, row, bag):
    sonar_msg = ThreeSonarDepth()
    sonar_msg.header.stamp = rospy.Time.from_sec(np.array(row["TimeStamp"], np.float128)/np.power(10,9))
    sonar_msg.distance_1 = row["Center_X"]
    sonar_msg.confidence_1 = row["Var_X"]
    sonar_msg.distance_2 = row["Center_Y"]
    sonar_msg.confidence_2 = row["Var_Y"]
    sonar_msg.distance_3 = 0
    sonar_msg.confidence_3 = 0
    sonar_msg.depth = 0
    
    sonar_pub.publish(sonar_msg)
    bag.write('/FLS_data', sonar_msg, sonar_msg.header.stamp)

if __name__ == '__main__':
    try:
        rospy.init_node('csv_to_rosbag', anonymous=True)
        csv_path = "/home/uwr/Desktop/2023_UWR/Analysis/processed_data/26Jan/FLS/11_13_03_Camera_sync.csv"  # Replace with the path to your CSV file
        sonar_pub = rospy.Publisher('/FLS_data', ThreeSonarDepth, queue_size=10)

        df = pd.read_csv(csv_path)
        rospy.loginfo(df.head())

        bag_path = '/home/uwr/Desktop/FLS_data_11_03.bag'  # Set your desired bag file path
        with rosbag.Bag(bag_path, 'w') as bag:
            for i, row in df.iterrows():
                sonar_data_publisher(sonar_pub=sonar_pub, row=row, bag=bag)

        rospy.loginfo("ROS Bag file created successfully!")

    except rospy.ROSInterruptException:
        pass
