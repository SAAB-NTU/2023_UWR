#include "ping1d.h"
#include <ros.h>
#include "sonar/Sonar.h"
#include "sonar/TwoSonar.h"
#include <std_msgs/String.h>
static const uint8_t arduinoRxPin = 19; //Serial1 rx
static const uint8_t arduinoTxPin = 18; //Serial1 tx





std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

static Ping1D ping { Serial1 };

static const uint8_t ledPin = 13;

sonar::Sonar sonar_msg;
sonar::TwoSonar sonar_msg2;

ros::Publisher sonar_arduino("sonar_arduino",&sonar_msg);
ros::Publisher sonar_arduino2("sonar_arduino2",&sonar_msg2);

ros::NodeHandle  nh;

void setup()
{
  Serial1.begin(57600);
  Serial.begin(57600);
  nh.initNode();
  nh.advertise(sonar_arduino);
  nh.advertise(sonar_arduino2);
  nh.advertise(chatter);
    while (!ping.initialize()) {
    Serial.println("\nPing device failed to initialize!");
    Serial.println("Are the Ping rx/tx wired correctly?");
    Serial.print("Ping rx is the green wire, and should be connected to Arduino pin ");
    Serial.print(arduinoTxPin);
    Serial.println(" (Arduino tx)");
    Serial.print("Ping tx is the white wire, and should be connected to Arduino pin ");
    Serial.print(arduinoRxPin);
    Serial.println(" (Arduino rx)");
    delay(2000);
  }
}
  char hello[13] = "hello world!";
void loop()
{
  
    sonar_msg.distance=ping.distance();
    sonar_msg.confidence=ping.confidence();
    sonar_msg.ping_number=ping.ping_number();
    sonar_msg.scan_start=ping.scan_start();
    sonar_msg.scan_length=ping.scan_length();
    sonar_msg.gain_setting=ping.gain_setting();
    sonar_msg.profile_data=ping.profile_data();
    sonar_arduino.publish(&sonar_msg);
    sonar_msg2.distance_1=ping.distance();
    sonar_arduino2.publish(&sonar_msg2);
     str_msg.data = hello;
    chatter.publish( &str_msg );
    if (ping.update()) {
    Serial.print("Distance: ");
    Serial.print(ping.distance());
    Serial.print("\tConfidence: ");
    Serial.println(ping.confidence());
  } else {
    Serial.println("No update received!");
  }

  nh.spinOnce();
  delay(1000);
}
