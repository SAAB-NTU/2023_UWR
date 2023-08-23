#!/usr/bin/env python3

import message_filters
import rospy
from geometry_msgs.msg import Vector3
from sensor_msgs.msg import Imu
from sonar.msg import Sonar
from nlink_parser.msg import TofsenseFrame0
import os
import csv
from threading import Lock

class logger:
    def __init__(self):
        self.filename = None
        self.csvwriter = None
        self.path = None
        self.lock = Lock()

    def create_csv_file(self):
        """
            If csv file name exists, increment i and use new i in name.
        """
        i = 0
        while os.path.exists(self.path + str(i) + ".csv"):
            i += 1
        self.filename = self.path + str(i)+".csv"

    def csv_writer(self,write_dict):
        """
            Thread lock is used to avoid two callbacks from accessing csvfile at the same time
        """
        self.lock.acquire()
        self.csvwriter.writerow(write_dict)
        self.lock.release()

    def callback_sonar_tof(self,sonar,tof):
        now = rospy.get_time()
        self.csv_writer({
                "time":now,"sensor":"sonar_tof","tof_distance":tof.dis,"sonar_distance":sonar.distance,"confidence":sonar.confidence
                })
        rospy.loginfo(sonar)
        rospy.loginfo(tof)

    def callback_tof(self,tof):
        now = rospy.get_time()
        self.csv_writer({
                "time":now,"sensor":"tof","tof_distance":tof.dis
                })
        rospy.loginfo(tof)

    def callback_sonar_distance(self,sonar):
        now = rospy.get_time()
        self.csv_writer({
                "time":now,"sensor":"sonar","sonar_distance":sonar.distance,"confidence":sonar.confidence
                })
        rospy.loginfo(sonar)
    
    def callback_sonar_profile(self,sonar):
        now = rospy.get_time()
        self.csv_writer({
                "time":now,"sensor":"sonar","sonar_distance":sonar.distance,"confidence":sonar.confidence,
                "transmit_duration":sonar.transmit_duration,"ping_number":sonar.ping_number,
                "scan_start":sonar.scan_start,"scan_length":sonar.scan_length,"gain_setting":sonar.gain_setting,
                "profile_data":[sonar.profile_data[i] for i in range(0,len(sonar.profile_data))],
                })
        rospy.loginfo(sonar)
    
    
    def callback_imu(self,imu):
        now = rospy.get_time()
        self.csv_writer({
                "time":now,"sensor":"imu",
                "accel x":imu.linear_acceleration.x,"accel y":imu.linear_acceleration.y,"accel z":imu.linear_acceleration.z,
                "angular_vel x":imu.angular_velocity.x,"angular_vel y":imu.angular_velocity.y,"angular_vel z":imu.angular_velocity.z,
                })
        rospy.loginfo(imu)

    def start(self):
        rospy.init_node("logger",anonymous=True)
        self.path = rospy.get_param("~csv_path","/home/ubuntu/all_log_")
        self.mode = rospy.get_param("~mode","all")
        self.create_csv_file()
        with open(self.filename,"w") as csvfile:
            if self.mode == "all":
                header = ["time","sensor","tof_distance","sonar_distance","confidence","accel x","accel y","accel z","angular_vel x","angular_vel y","angular_vel z"]
                self.csvwriter = csv.DictWriter(csvfile,fieldnames = header)
                self.csvwriter.writeheader()
                imu_sub = rospy.Subscriber("/imu/data_raw",Imu,self.callback_imu,queue_size=1)

                # Code below is to time synchronize sonar and tof mesurements
                sonar_sub = message_filters.Subscriber('/sonar', Sonar)
                tof_sub = message_filters.Subscriber('/nlink_tofsense_frame0',TofsenseFrame0)
                ts = message_filters.ApproximateTimeSynchronizer([sonar_sub,tof_sub],1,0.01,allow_headerless=True)
                ts.registerCallback(self.callback_sonar_tof)
                
            elif self.mode == "imu_tof":
                header = ["time","sensor","tof_distance","accel x","accel y","accel z","angular_vel x","angular_vel y","angular_vel z"]
                self.csvwriter = csv.DictWriter(csvfile,fieldnames = header)
                self.csvwriter.writeheader()
                imu_sub = rospy.Subscriber("/imu/data_raw",Imu,self.callback_imu)
                tof_sub = rospy.Subscriber('/nlink_tofsense_frame0',TofsenseFrame0,self.callback_tof)

            elif self.mode == "imu":
                header = ["time","sensor","accel x","accel y","accel z","angular_vel x","angular_vel y","angular_vel z"]
                self.csvwriter = csv.DictWriter(csvfile,fieldnames = header)
                self.csvwriter.writeheader()
                imu_sub = rospy.Subscriber("/imu/data_raw",Imu,self.callback_imu)
                
            elif self.mode == "sonar":
                header = ["time","sensor","sonar_distance","confidence","transmit_duration","ping_number","scan_start","scan_length","gain_setting","profile_data"]
                self.csvwriter = csv.DictWriter(csvfile,fieldnames = header)
                self.csvwriter.writeheader()
                sonar_sub = rospy.Subscriber('/sonar', Sonar,self.callback_sonar_profile)
                
            elif self.mode == "tof":
                header = ["time","sensor","tof_distance"]
                self.csvwriter = csv.DictWriter(csvfile,fieldnames = header)
                self.csvwriter.writeheader()
                tof_sub = rospy.Subscriber('/nlink_tofsense_frame0',TofsenseFrame0,self.callback_tof)
            rospy.spin()
            

if __name__ == "__main__":
    try:
        log = logger().start()
    except rospy.ROSInterruptException:
        pass
