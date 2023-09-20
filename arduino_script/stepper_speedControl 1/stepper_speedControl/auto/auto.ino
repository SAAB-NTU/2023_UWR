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
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(delay_time);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delay_time);
    }
  }
  
}

void step_calculator(float distance)
{
  float rotate_angle = (distance/(2*PI*0.0315))*360;
  float pulse_angle = (1.8/8);
  steps = rotate_angle/pulse_angle;
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
    Serial.println("Please input distance to travel");
    while(Serial.available()== 0){}
    distance = Serial.parseFloat();
    step_calculator(distance);
    Serial.print("Steps : ");Serial.print(steps);Serial.println();
  }
  if (delay_time==0)
  {
    Serial.println("Please input delay time(microsec) e.g. 1000,800");
    while(Serial.available()== 0){}
    delay_time = Serial.parseInt(); //1000,800,500 (500 used in first exp,1000 in most recent)
    Serial.print("Delay time : ");Serial.print(delay_time);Serial.println();
  }
  while (Serial.available() > 0)
  {
    char c = Serial.read();
    switch (c)
    {
      case 'f': //forward
        motor(steps,LOW,delay_time);
        //delay(5000); //motor stop time 5s
        //motor(steps,LOW,delay_time);
        break; 
        
      case 'b': //go back to original position
        motor(1*steps,HIGH,delay_time);
        break; 
    }
  }
}
