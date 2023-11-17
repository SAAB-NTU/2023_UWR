#!/usr/bin/env python3

import rospy
from sonar.msg import ThreeSonarDepth
from brping import Ping1D
import ms5837
'''
def publish_sonar_profile():
    sonar_driver = Ping1D()
    sonar_port = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB0")
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
        '''

def publish_sonar_distance():

    rospy.init_node("single_beam_sonar_node")
    pub_sonar = rospy.Publisher("sonar", Sonar, queue_size=1)

    sonar_driver1 = Ping1D()
    sonar_port1 = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB0")
    ping_interval = rospy.get_param("/sonar/ping_interval",100)
    sonar_driver1.connect_serial(device_name=sonar_port1)
    sonar_driver1.set_ping_interval(ping_interval) #default is 250ms

    sonar_driver2 = Ping1D()
    sonar_port2 = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB1")
    
    sonar_driver2.connect_serial(device_name=sonar_port2)
    sonar_driver2.set_ping_interval(ping_interval) #default is 250ms

    sonar_driver3 = Ping1D()
    sonar_port3 = rospy.get_param("/sonar/sonar_port","/dev/ttyUSB2")
    
    sonar_driver3.connect_serial(device_name=sonar_port3)
    sonar_driver3.set_ping_interval(ping_interval) #default is 250ms

    if not sensor.init():
        print("Depth Sensor could not be initialized")
        

# We have to read values from sensor to update pressure and temperature
    if not sensor.read():
        print("Depth Sensor read failed!")
    


    sensor = ms5837.MS5837_30BA()

    while not rospy.is_shutdown():
        sonar_msg = ThreeSonarDepth()
        data_1 = sonar_driver1.get_distance_simple()
        data_2 = sonar_driver2.get_distance_simple()
        data_3 = sonar_driver3.get_distance_simple()

        if(sensor.read()):
            sonar_msg.depth= sensor.depth()/1000

        
        sonar_msg.header.stamp = rospy.Time.now()
        sonar_msg.distance_1 = data_1["distance"] / 1000.0
        sonar_msg.confidence_1 = data_1["confidence"]
        sonar_msg.distance_2 = data_2["distance"] / 1000.0
        sonar_msg.confidence_2 = data_2["confidence"]
        sonar_msg.distance_3 = data_3["distance"] / 1000.0
        sonar_msg.confidence_3 = data_3["confidence"]


        pub_sonar.publish(sonar_msg)
        rospy.loginfo(
            "logged"
        )
        #sleep(0.01) #check if adding delay helps
'''
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
        '''

        
if __name__ == "__main__":
    try:
        
        publish_sonar_distance()
     
    except rospy.ROSInterruptException:
        pass
