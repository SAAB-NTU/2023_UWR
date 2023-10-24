/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;


void messageCb(const std_msgs::Bool& toggle_msg) {
  if (toggle_msg.data == true) {
    digitalWrite(13, HIGH); // Turn the LED on
  } else {
    digitalWrite(13, LOW); // Turn the LED off
  }
}


ros::Subscriber<std_msgs::Bool> sub("toggle_led", messageCb );



void setup()
{
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
}
