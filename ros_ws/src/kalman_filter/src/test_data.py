#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
from sonar.msg import ThreeSonarDepth
from std_msgs.msg import Header
from random import uniform
from std_msgs.msg import Float64

rospy.init_node('data_publisher', anonymous=True)
last_sonar_noise_time = rospy.Time.now()

def imu_data_publisher(data):
    
    #rate = rospy.Rate(1)  # 1 Hz
    

    imu_msg = data
    #imu_msg.linear_acceleration.x = uniform(-1.0, 1.0)
    #imu_msg.linear_acceleration.y = uniform(-1.0, 1.0)
    #imu_msg.linear_acceleration.z = uniform(-1.0, 1.0)
    imu_pub.publish(imu_msg)
    #rate.sleep()

def sonar_data_publisher(data):
    global last_sonar_noise_time
    #rate = rospy.Rate(100)  # 1 Hz

    
    
    sonar_msg=data

    if((rospy.Time.now()-last_sonar_noise_time).to_sec()>2):

        rospy.loginfo("Added Noise")
        sonar_msg.distance_1*=uniform(-5.0, 5.0)
        sonar_msg.distance_2*=uniform(-5.0, 5.0)
        sonar_msg.distance_3*=uniform(-5.0, 5.0)
        last_sonar_noise_time=rospy.Time.now()
    #sonar_msg.distance_1 = uniform(0.0, 2.0)
    #sonar_msg.confidence_1 = 100.0
    #sonar_msg.distance_2 = uniform(0.0, 2.0)
    #sonar_msg.confidence_2 = 100.0
    #sonar_msg.distance_3 = uniform(0.0, 2.0)
    #sonar_msg.confidence_3 = 100.0
    #depth = uniform(0.0, 2.0)
    #sonar_msg.depth=depth
    
    

    #depth_msg.data=depth
    #sonar_msg.altitude = uniform(0.0, 10.0)
    #sonar_msg.pressure = uniform(0.0, 10.0)
    sonar_pub.publish(sonar_msg)
    #depth_pub.publish(depth_msg)
    #rate.sleep()

if __name__ == '__main__':
    try:

        
        imu_pub = rospy.Publisher('/imu/data', Imu, queue_size=10)
        #rospy.init_node('sonar_data_publisher', anonymous=True)
        sonar_pub = rospy.Publisher('/ThreeSonarDepth', ThreeSonarDepth, queue_size=10)
        #depth_pub = rospy.Publisher('/depth_msg', Float64, queue_size=10)

        rospy.Subscriber("/SONAR_raw",ThreeSonarDepth,sonar_data_publisher)
        rospy.Subscriber("/IMU_raw",Imu,imu_data_publisher)


        #while not rospy.is_shutdown():
            #imu_data_publisher(imu_pub=imu_pub)
            #sonar_data_publisher(sonar_pub=sonar_pub,depth_pub=depth_pub)
            
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
