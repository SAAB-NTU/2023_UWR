#!/usr/bin/env python3
import rospy
from stepper_motor_control.srv import comms1
from std_msgs.msg import Bool
import numpy as np
import serial

pulse_val=1.8/8
const_val=360/(2*np.pi*0.0315)
pub=rospy.Publisher('toggle_led',Bool,queue_size=1)


def move_motor(steps,direction,delay_time,no_stops,stop_steps,stop_duration):
    
    rospy.loginfo("hello")
    rate=rospy.Rate(1000/delay_time)
    
    if no_stops==0:
        rospy.loginfo("in")
        for step in range(steps):
            #rospy.loginfo("loop")
            pub.publish(direction)
            rospy.loginfo(direction)
            rate.sleep()
            pub.publish(not direction)
            rospy.loginfo(not direction)
            rate.sleep()
    else:

        for stops in range(no_stops):
            for step in range(stop_steps):
                rospy.loginfo("loop")
                pub.publish(direction)
                #rospy.loginfo(ser.readline())
                rate.sleep()
                pub.publish(not direction)
                #rospy.loginfo(ser.readline())
                rate.sleep()

        rospy.sleep(stop_duration)        
    rospy.loginfo("over")
 
def motor_service_callback(request):
    rospy.loginfo("hi")
    
    rotate_angle=request.distance*const_val
    steps=rotate_angle//pulse_val
    if(request.stops>0):
        stop_step=steps//request.stops
    else:
        stop_step=0

    move_motor(int(steps),request.dir,request.delay,request.stops,int(stop_step),request.stop_duration)

    return int(steps)

def uwr_service_server():
    rospy.init_node('stepper_motor_server')

    # Create the service
    rospy.Service('stepper_motor_service', comms1, motor_service_callback)
    
    rospy.spin()

if __name__ == '__main__':
    try:
        uwr_service_server()
    except rospy.ROSInterruptException:
        pass