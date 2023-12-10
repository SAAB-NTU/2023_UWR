#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
from sonar.msg import ThreeSonarDepth
from std_msgs.msg import Header
from random import uniform
from std_msgs.msg import Float64
import pandas as pd
import numpy as np
from glob import glob

time=0
i=0

paths=sorted(glob("/home/saab/Desktop/2023_UWR/Analysis/raw_data/Nov_21/KF/*"))


def imu_data_publisher(imu_pub,row):
    
    #rate = rospy.Rate(1)  # 1 Hz
    

    imu_msg = Imu()
    imu_msg.header.stamp=rospy.Time.from_sec(np.array(row["time"],np.float128))
    imu_msg.linear_acceleration.x = row["sonar_distance_x"]
    imu_msg.linear_acceleration.y = row["sonar_distance_y"]
    imu_msg.linear_acceleration.z = row["depth_z"]
    imu_pub.publish(imu_msg)
    #rate.sleep()

def sonar_data_publisher(sonar_pub,depth_pub,row):

    #rate = rospy.Rate(100)  # 1 Hz

    
    sonar_msg = ThreeSonarDepth()
    sonar_msg.header.stamp = rospy.Time.from_sec(np.array(row["time"],np.float128))
    sonar_msg.distance_1 = row["sonar_distance_x"]
    sonar_msg.confidence_1 = 100.0
    sonar_msg.distance_2 = row["sonar_distance_y"]
    sonar_msg.confidence_2 = 100.0
    sonar_msg.distance_3 = row["depth_z"]
    sonar_msg.confidence_3 = 100.0
    depth = row["depth_z"]
    sonar_msg.depth=depth
    depth_msg=Float64()
    
    #depth_msg.data=depth
    #sonar_msg.altitude = uniform(0.0, 10.0)
    #sonar_msg.pressure = uniform(0.0, 10.0)
    sonar_pub.publish(sonar_msg)
    #depth_pub.publish(depth_msg)
    #rate.sleep()

if __name__ == '__main__':
    try:

        
        rospy.init_node('data_publisher', anonymous=True)
        path=paths[rospy.get_param("~csv_path")]
        imu_pub = rospy.Publisher('/imu/data', Imu, queue_size=10)
        #rospy.init_node('sonar_data_publisher', anonymous=True)
        sonar_pub = rospy.Publisher('/ThreeSonarDepth', ThreeSonarDepth, queue_size=10)
        depth_pub = rospy.Publisher('/depth_msg', Float64, queue_size=10)
        df=pd.read_csv(path)
        rospy.loginfo(df.head())
        time=np.asarray(rospy.Time.now().to_sec(),np.float128)
        df.iloc[:]["time"]-=df.iloc[0]["time"]
        while not rospy.is_shutdown():
            if(i<len(df)):
                time_now=rospy.Time.now()
                rospy.loginfo(i)
                if(time_now.to_sec()-time>df.iloc[i]["time"]):
                    if(df.iloc[i]["sensor"]=="imu"):
                        imu_data_publisher(imu_pub=imu_pub,row=df.iloc[i])
                    else:
                        sonar_data_publisher(sonar_pub=sonar_pub,depth_pub=depth_pub,row=df.iloc[i])
                    time=np.asarray(df.iloc[i]["time"],np.float128)
                    i+=1
                    
            else:
                
                rospy.signal_shutdown("done")
        #rospy.spin()
    except rospy.ROSInterruptException:
        pass
