#include <Servo.h>

Servo myservo;
int degree;
int steps = 1; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  degree = 0; //set the degree 0
}

void loop() { 
  //
  myservo.write(degree);
  delay(15);
  //we have to loop in range of 0 to 90 degree and then 90 to 0 degree
  //so when the value of variable(degree) become 90 the
  //steps intialize to -1 because we want to decrease and vice versa.
  //value of degree to zero .
  if(degree == 90)
    steps = -1;
  if(degree == 0)
    steps = 1;
    
  //sum the value 
  degree += steps ;
}
