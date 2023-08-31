#!/usr/bin/env python3

import rospy
from uwr_comms.srv import comms1
import numpy as np
import serial

def str_service_callback(request):
    # Process the received JSON message
    data=(np.array(request.data)+181)/255
    serial_port = "/dev/ttyACM0"  # Replace with your serial port name
    baud_rate = 9600
    ser = serial.Serial(serial_port, baud_rate)

    # Send data over UART
    data_to_send = '{"A":10,"B":10}'
    ser.write(data_to_send.encode())

    # Close the UART port
    ser.close()
    response="success"
    return response,data

def uwr_service_server():
    rospy.init_node('uwr_service_server')

    # Create the service
    rospy.Service('uwr_comms_service', comms1, str_service_callback)

    rospy.spin()

if __name__ == '__main__':
    try:
        uwr_service_server()
    except rospy.ROSInterruptException:
        pass