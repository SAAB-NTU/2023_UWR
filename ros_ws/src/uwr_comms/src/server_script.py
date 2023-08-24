#!/usr/bin/env python3

import rospy
from uwr_comms.srv import comms1
import json

def str_service_callback(request):
    # Process the received JSON message
    message = request.str
    # Perform necessary operations with the JSON data
    # ...

    # Prepare the response message
    response = {
        "result": "Success",
        "data": message
    }



    return message

def json_service_server():
    rospy.init_node('json_service_server')

    # Create the service
    rospy.Service('json_service', comms1, str_service_callback)

    rospy.spin()

if __name__ == '__main__':
    try:
        json_service_server()
    except rospy.ROSInterruptException:
        pass