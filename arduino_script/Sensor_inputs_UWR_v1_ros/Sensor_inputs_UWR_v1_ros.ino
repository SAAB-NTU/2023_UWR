#include "ping1d.h"
#include <Wire.h>
#include "MS5837.h"

#include <ros.h>
#include  "sonar/ThreeSonarDepth.h" //NEW


MS5837 sensor;


static const uint8_t arduinoRxPin1 = 15; //Serial1 rx sonar front OR 2
static const uint8_t arduinoTxPin1 = 14; //Serial1 tx sonar front OR 2

static const uint8_t arduinoRxPin2 = 19; //Serial2 rx sonar left OR 1
static const uint8_t arduinoTxPin2 = 18; //Serial2 tx sonar left OR 1


static const uint8_t arduinoRxPin3 = 17; //Serial3 rx sonar right OR 3
static const uint8_t arduinoTxPin3 = 16; //Serial3 tx sonar right OR 3

static Ping1D ping1 { Serial1}; //creating an instance with a seperate interface
static Ping1D ping2 { Serial2}; //creating an instance with a seperate interface
static Ping1D ping3 { Serial3}; //creating an instance with a seperate interface

sonar::ThreeSonarDepth combined_data; 

ros::Publisher ThreeSonarDepth("ThreeSonarDepth",&combined_data);

ros::NodeHandle nh; // creates an instance for a ROS-node-handler

void setup()
{

     Wire.begin();
 // Initialize pressure sensor
  // Returns true if initialization was successful
  // We can't continue with the rest of the program unless we can initialize the sensor
  while (!sensor.init()) {
    if(!nh.connected()){
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");
    }
    delay(5000);

  }
  sensor.setModel(MS5837::MS5837_30BA);
  sensor.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)

//SONARs can only take 9600 or 115200 baud rates, any other rate will result in errors

  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);

  Serial.begin(57600);

  if(!nh.connected()){
  Serial.println("Blue Robotics ping1d-simple.ino");
  }
  
  while (!ping1.initialize() & !ping2.initialize() & !ping3.initialize() ) {
    if(!nh.connected()){
    Serial.println("\nPing device failed to initialize!");
    Serial.println("Are the Ping rx/tx wired correctly?");

    Serial.print("Ping1 rx is the green wire, and should be connected to Arduino pin ");
    Serial.print(arduinoTxPin1);
    Serial.println(" (Arduino tx)");

    Serial.print("Ping2 rx is the green wire, and should be connected to Arduino pin ");
    Serial.print(arduinoTxPin2);
    Serial.println(" (Arduino tx)");

    Serial.print("Ping3 rx is the green wire, and should be connected to Arduino pin ");
    Serial.print(arduinoTxPin3);
    Serial.println(" (Arduino tx)");

    Serial.print("Ping1 tx is the white wire, and should be connected to Arduino pin ");
    Serial.print(arduinoRxPin1);
    Serial.println(" (Arduino rx)");

    Serial.print("Ping2 tx is the white wire, and should be connected to Arduino pin ");
    Serial.print(arduinoRxPin2);
    Serial.println(" (Arduino rx)");

    Serial.print("Ping3 tx is the white wire, and should be connected to Arduino pin ");
    Serial.print(arduinoRxPin3);
    Serial.println(" (Arduino rx)");
    }

    delay(2000);
 
}
nh.initNode();
nh.advertise(ThreeSonarDepth);

}

void initialize()
{
  combined_data.distance_1 = 0.0; //NEW
  combined_data.distance_2 = 0.0; //NEW
  combined_data.distance_3 = 0.0; //NEW
  combined_data.confidence_1 = 0.0; //NEW
  combined_data.confidence_2 = 0.0; //NEW
  combined_data.confidence_3 = 0.0; //NEW
  combined_data.altitude=0;
  combined_data.depth=0;
  combined_data.pressure=0;
}


void loop()
{
  //Serial.begin(57600);
  combined_data.header.stamp = nh.now(); //current ros time; reveive & process messages in right sequences
  if(!nh.connected())
  Serial.println("In loop");
  initialize();
  if (ping1.update()) {

    combined_data.distance_1 =ping1.distance(); 
    //NEW
    combined_data.confidence_1 =ping1.confidence();
   
     //NEW

  } 

    if (ping2.update()) {
 
    combined_data.distance_2 = ping2.distance(); //NEW
    combined_data.confidence_2 = ping2.confidence(); //NEW
    

  } 

    if (ping3.update()) {

    combined_data.distance_3 = ping3.distance(); // NEW
    combined_data.confidence_3 = ping3.confidence(); //NEW
    
    }
    delay(50);
  
  sensor.read();


  combined_data.pressure = sensor.pressure();
  

  combined_data.depth = sensor.depth();

  combined_data.altitude = sensor.altitude();
  delay(50);
  if(!nh.connected())
Serial.println("publishing");

  ThreeSonarDepth.publish(&combined_data);
  
  //Include the line below

  nh.spinOnce();

}
