#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion
import math
import csv

with open("/home/zejie/Desktop/complementary_mag.csv",'w') as file:
    roll = pitch = yaw = 0.0
    csvwriter = csv.writer(file)

    def get_rotation (msg):
        global roll, pitch, yaw
        orientation_q = msg.orientation
        orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, yaw) = euler_from_quaternion (orientation_list)
        csvwriter.writerow([yaw * 180/math.pi])
        print(yaw * 180/math.pi)

    rospy.init_node('my_quaternion_to_euler')

    sub = rospy.Subscriber ('/imu/data', Imu, get_rotation)

    rospy.spin()