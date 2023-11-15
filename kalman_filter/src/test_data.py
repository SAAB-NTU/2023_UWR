#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
from sonar.msg import ThreeSonarDepth
from std_msgs.msg import Header
from random import uniform
from std_msgs.msg import Float64

def imu_data_publisher(imu_pub):
    
    rate = rospy.Rate(1)  # 1 Hz
    

    imu_msg = Imu()
    imu_msg.header = Header()
    imu_msg.linear_acceleration.x = uniform(-1.0, 1.0)
    imu_msg.linear_acceleration.y = uniform(-1.0, 1.0)
    imu_msg.linear_acceleration.z = uniform(-1.0, 1.0)
    imu_pub.publish(imu_msg)
    rate.sleep()

def sonar_data_publisher(sonar_pub,depth_pub):

    rate = rospy.Rate(100)  # 1 Hz

    
    sonar_msg = ThreeSonarDepth()
    sonar_msg.header = Header()
    sonar_msg.distance_1 = uniform(0.0, 2.0)
    sonar_msg.confidence_1 = 100.0
    sonar_msg.distance_2 = uniform(0.0, 2.0)
    sonar_msg.confidence_2 = 100.0
    sonar_msg.distance_3 = uniform(0.0, 2.0)
    sonar_msg.confidence_3 = 100.0
    depth = uniform(0.0, 2.0)
    sonar_msg.depth=depth
    depth_msg=Float64()
    
    depth_msg.data=depth
    sonar_msg.altitude = uniform(0.0, 10.0)
    sonar_msg.pressure = uniform(0.0, 10.0)
    sonar_pub.publish(sonar_msg)
    depth_pub.publish(depth_msg)
    rate.sleep()

if __name__ == '__main__':
    try:
        rospy.init_node('data_publisher', anonymous=True)
        imu_pub = rospy.Publisher('/camera/accel/sample', Imu, queue_size=10)
        #rospy.init_node('sonar_data_publisher', anonymous=True)
        sonar_pub = rospy.Publisher('/ThreeSonarDepth', ThreeSonarDepth, queue_size=10)
        depth_pub = rospy.Publisher('/depth_msg', Float64, queue_size=10)
        while not rospy.is_shutdown():
            imu_data_publisher(imu_pub=imu_pub)
            sonar_data_publisher(sonar_pub=sonar_pub,depth_pub=depth_pub)
        #rospy.spin()
    except rospy.ROSInterruptException:
        pass
