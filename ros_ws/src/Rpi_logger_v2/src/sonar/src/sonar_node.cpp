#include <ping-device-ping1d.h>
#include <ping-message-ping1d.h>
#include <abstract-link.h>
#include <ros/ros.h>
#include <sonar/Sonar.h>
#include <string>

std::string port;
int ping_interval;

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"sonar");
    ros::NodeHandle n;

    n.getParam("/sonar/port",port="/dev/ttyUSB1");
    ROS_INFO("%s",port.c_str());

    n.getParam("/sonar/ping_interval",ping_interval=250);
    ROS_INFO("%d",ping_interval);

    ros::Publisher sonar_pub = n.advertise<sonar::Sonar>("sonar",1); 
    
    std::string url = "serial:" + port + ":115200";
    auto port = AbstractLink::openUrl(url);
    Ping1d device = Ping1d(*port.get());
    if(device.initialize(ping_interval))
    {
	//ROS_INFO("ping interval: %d",device.get_ping_interval());
        while (ros::ok())
        {
            if (device.request(Ping1dId::DISTANCE_SIMPLE,1000))
            {
                uint32_t distance = device.distance_simple_data.distance;
		ROS_INFO("distance: %f",(distance/1000.0));
                uint8_t confidence = device.distance_simple_data.confidence;
		ROS_INFO("confidence: %d",confidence);
                sonar::Sonar sonar_msg;
                sonar_msg.distance = distance/1000.0;
                sonar_msg.confidence = confidence;
                sonar_msg.header.stamp = ros::Time::now();
                sonar_pub.publish(sonar_msg);
            }
        }
    }
    return 0;
}
