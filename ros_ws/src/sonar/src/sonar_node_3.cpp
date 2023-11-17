#include <ping-device-ping1d.h>
#include <ping-message-ping1d.h>
#include <abstract-link.h>
#include <ros/ros.h>
#include <sonar/Sonar.h>
#include <sonar/ThreeSonarDepth.h>
#include <string>

std::string port1,port2,port3;
int ping_interval;
uint32_t distance_1,distance_2,distance_3,confidence_1,confidence_2,confidence_3;

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"sonar");
    ros::NodeHandle n;

    n.getParam("/sonar/port1",port1="/dev/ttyUSB0");
    ROS_INFO("%s",port1.c_str());
    n.getParam("/sonar/port2",port2="/dev/ttyUSB1");
    ROS_INFO("%s",port2.c_str());
    n.getParam("/sonar/port2",port3="/dev/ttyUSB2");
    ROS_INFO("%s",port3.c_str());

    n.getParam("/sonar/ping_interval",ping_interval=250);
    ROS_INFO("%d",ping_interval);

    ros::Publisher sonar_pub = n.advertise<sonar::Sonar>("sonar",1); 
    
    std::string url1 = "serial:" + port1 + ":9600";
    std::string url2 = "serial:" + port2 + ":9600";
    std::string url3 = "serial:" + port3 + ":9600";
    
    auto port1 = AbstractLink::openUrl(url1);
    auto port2 = AbstractLink::openUrl(url2);
    auto port3 = AbstractLink::openUrl(url3);
    
    Ping1d device1 = Ping1d(*port1.get());
    Ping1d device2 = Ping1d(*port2.get());
    Ping1d device3 = Ping1d(*port3.get());
    
    sonar::ThreeSonarDepth sonar_msg;
    
    while (ros::ok())
        {
            if(device1.initialize(ping_interval))
            {
	//ROS_INFO("ping interval: %d",device.get_ping_interval());

            if (device1.request(Ping1dId::DISTANCE_SIMPLE,1000))
                {
                    distance_1 = device1.distance_simple_data.distance;
                    ROS_INFO("distance: %f",(distance_1/1000.0));
                    confidence_1 = device1.distance_simple_data.confidence;
                    ROS_INFO("confidence: %d",confidence_1);
                    
                    sonar_msg.distance_1 = distance_1/1000.0;
                    sonar_msg.confidence_1 = confidence_1;
                }
            }
      
        
            if(device2.initialize(ping_interval))
                {
	//ROS_INFO("ping interval: %d",device.get_ping_interval());

                if (device2.request(Ping1dId::DISTANCE_SIMPLE,1000))
                    {
                        distance_2 = device2.distance_simple_data.distance;
                        ROS_INFO("distance: %f",(distance_2/1000.0));
                        confidence_2 = device2.distance_simple_data.confidence;
                        ROS_INFO("confidence: %d",confidence_2);
                        
                        sonar_msg.distance_2 = distance_2/1000.0;
                        sonar_msg.confidence_2 = confidence_2;
                    }
                }
            
            if(device3.initialize(ping_interval))
                {
	//ROS_INFO("ping interval: %d",device.get_ping_interval());

                if (device3.request(Ping1dId::DISTANCE_SIMPLE,1000))
                    {   
                        distance_3 = device3.distance_simple_data.distance;
                        ROS_INFO("distance: %f",(distance_3/1000.0));
                        confidence_3 = device3.distance_simple_data.confidence;
                        ROS_INFO("confidence: %d",confidence_3);
                    }
                    sonar_msg.distance_3 = distance_3/1000.0;
                    sonar_msg.confidence_3 = confidence_3;

                }
            
                sonar_msg.header.stamp = ros::Time::now();
                sonar_pub.publish(sonar_msg);

            }
       
       

        return 0;
    }
    
