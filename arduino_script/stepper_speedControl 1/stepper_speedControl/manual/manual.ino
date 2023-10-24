//In Serial Monitor,
//Type r + enter to run motor
//Type s + enter to stop motor
//Type d + enter to change direction 

//Change mode values to change step duration, higher means more delay, slower
//500 used in 1st exp, 1000 in 2nd exp

#define dirPin 2 
#define stepPin 3

int mode;
int i = 0;
int direction = HIGH;
void setup()
{
  // Declare pins as output:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the spinning direction CW/CCW:
  digitalWrite(dirPin, LOW);
  Serial.println("OK");
}

void loop()
{
  while (Serial.available() > 0)
  {
    char c = Serial.read();
    switch (c)
    {
      case 'r': mode = 1000; i = 1; break;
      case 'd': i = 0; digitalWrite(dirPin, not direction); direction = not direction ;break; //change direction
      case 's': i = 0; break;//stop
    }
  }
  // These four lines result in 1 step:
  if (i == 1)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(mode);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(mode);
  }
}
