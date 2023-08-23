#!/usr/bin/env python3

import rospy
from sonar.msg import Sonar
from brping import Ping1D

def publish_sonar_profile():
    sonar_driver = Ping1D()
    sonar_port = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB1")
    sonar_driver.connect_serial(device_name=sonar_port)
    rospy.init_node("single_beam_sonar_node")
    pub_sonar = rospy.Publisher("sonar", Sonar, queue_size=1)
    while not rospy.is_shutdown():
        data = sonar_driver.get_profile()
        sonar_msg = Sonar()
        sonar_msg.header.stamp = rospy.Time.now()
        sonar_msg.distance = data["distance"] / 1000.0
        sonar_msg.confidence = data["confidence"]
        sonar_msg.transmit_duration = data["transmit_duration"]
        sonar_msg.ping_number = data["ping_number"]
        sonar_msg.scan_start = data["scan_start"]
        sonar_msg.scan_length = data["scan_length"]
        sonar_msg.gain_setting = data["gain_setting"]
        sonar_msg.profile_data = data["profile_data"]
        pub_sonar.publish(sonar_msg)
        rospy.loginfo(
            data
        )

def publish_sonar_distance():
    sonar_driver = Ping1D()
    sonar_port = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB1")
    ping_interval = rospy.get_param("/sonar/ping_interval",100)
    sonar_driver.connect_serial(device_name=sonar_port)
    sonar_driver.set_ping_interval(ping_interval) #default is 250ms
    print(sonar_driver.get_ping_interval())
    rospy.init_node("single_beam_sonar_node")
    pub_sonar = rospy.Publisher("sonar", Sonar, queue_size=1)
    while not rospy.is_shutdown():
        data = sonar_driver.get_distance_simple()
        sonar_msg = Sonar()
        sonar_msg.header.stamp = rospy.Time.now()
        sonar_msg.distance = data["distance"] / 1000.0
        sonar_msg.confidence = data["confidence"]
        pub_sonar.publish(sonar_msg)
        rospy.loginfo(
            data
        )
        #sleep(0.01) #check if adding delay helps

def publish_sonar_simulated():
    rospy.init_node("single_beam_sonar_node")
    pub_sonar = rospy.Publisher("sonar", Sonar, queue_size=1)
    r = rospy.Rate(20)
    while not rospy.is_shutdown():
        data = {"distance":1000,"confidence":100}
        sonar_msg = Sonar()
        sonar_msg.header.stamp = rospy.Time.now()
        sonar_msg.distance = data["distance"] / 1000.0
        sonar_msg.confidence = data["confidence"]
        pub_sonar.publish(sonar_msg)
        rospy.loginfo(sonar_msg)
        r.sleep()

        
if __name__ == "__main__":
    try:
        mode = rospy.get_param("/sonar/mode","distance")
        if mode == "profile":
            publish_sonar_profile()
        elif mode == "distance":
            publish_sonar_distance()
        elif mode == "simulated":
            publish_sonar_simulated()
    except rospy.ROSInterruptException:
        pass
