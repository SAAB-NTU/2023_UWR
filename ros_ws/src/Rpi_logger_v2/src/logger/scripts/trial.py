#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Imu
import pandas as pd
from tf.transformations import euler_from_quaternion
import time

def imu_callback(data):
    with open("/home/zejie/Desktop/yes.csv","a") as f:
        (roll, pitch, yaw) = euler_from_quaternion ([data.orientation.x, data.orientation.y, data.orientation.z, data.orientation.w])
        f.write(str(data.header.stamp.secs) + '.' + str(data.header.stamp.nsecs) + "," + str(yaw)+"\n")
        

if __name__ == "__main__":
    rospy.init_node("trial",anonymous=True)
    rospy.Subscriber("/imu/data",Imu,imu_callback,queue_size=1)
    pub = rospy.Publisher("/imu/data_raw",Imu,queue_size=1)
    df = pd.read_csv("/home/zejie/Desktop/data/two_sonar_7.csv")
    i = 0
    while not rospy.is_shutdown() and i!=len(df):
        if df["sensor"][i] == "imu":
            imu_data = Imu() 
            imu_data.header.stamp = rospy.Time.from_sec(df["time"][i])
            imu_data.linear_acceleration.x = df["accel x"][i]
            imu_data.linear_acceleration.y = df["accel y"][i]
            imu_data.linear_acceleration.z = df["accel z"][i]
            imu_data.angular_velocity.x = df["angular_vel x"][i]
            imu_data.angular_velocity.y = df["angular_vel y"][i]
            imu_data.angular_velocity.z = df["angular_vel z"][i]
            pub.publish(imu_data)
            print(i)
            time.sleep(0.001)
        i += 1
    rospy.spin()
