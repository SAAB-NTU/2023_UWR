//Program runs motor for a distance and stop for a few seconds and then move
//User input: 1.)distance before stopping (1/2 of total distance)e.g. 2 if rig moves 4m in total
//            2.)speed of motor in terms of pulse duration (1000 is slow, 500 is fast)

//Afterwards, type 
//(a.) f to move forward
//(b.) b to go back to starting position *returning speed change in line 85

//Special Note:
//1.Stop the motor any time by restarting arduino
//2.Stopping time can be changed in line 80

#define dirPin 2
#define stepPin 3

#include <ros.h>
#include <std_msgs/String.h>

int delay_time = 0;//microseconds
int steps = 0;
float distance;

void motor(int steps,int directions,int delay_time) 
{
  if(delay_time == 0)
  {
    Serial.println("Choose speed!");
  }
  else
  {
    digitalWrite(dirPin, directions);
    for(int i =0;i<steps;i++)
    {
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delay_time);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(delay_time);
    }
  }
  
}

void step_calculator(float distance)
{
  Serial.println("In");
  double constant= 360/(2*PI*31.5); //0.0315 m -->31.5 mm
  double rotate_angle = (distance)*constant;
  double pulse_angle = (1.8/32);
  steps = int(rotate_angle/pulse_angle);
  Serial.println("Out");
}

void setup()
{
  // Declare pins as output:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.println("Start");
}

void loop()
{
  if(steps==0)
  {
    Serial.println("Please input distance to travel (in mm)");
    while(Serial.available()== 0){}
    distance = Serial.parseInt();
    Serial.println(distance);
    step_calculator(distance);
    Serial.print("Steps : ");Serial.print(steps);Serial.println();
  }
  if (delay_time==0)
  {
    Serial.println("Please input delay time(microsec) e.g. 1000,800");
    while(Serial.available()== 0){}
    delay_time = Serial.parseInt(); //1000,800,500 (500 used in first exp,1000 in most recent)
    Serial.print("Delay time : ");Serial.println(delay_time);

    Serial.println("Ready to operate (f- forward, b- backward) ");

  }
  while (Serial.available() > 0)
  {
    char c = Serial.read();
    switch (c)
    {
      case 'f': //forward
        {
          Serial.println("Going forward");
          motor(steps,LOW,delay_time);
          Serial.println("Complete");
        }
        //delay(5000); //motor stop time 5s
        //motor(steps,LOW,delay_time);
        break; 
        
      case 'b': //go back to original position
        {
          Serial.println("Going back");
          motor(steps,HIGH,delay_time);
          Serial.println("Complete");
        }
        break; 
    }
  }
}
