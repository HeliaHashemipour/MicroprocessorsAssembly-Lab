#include <Servo.h>
#include <Keypad.h>
int val;
Servo myservo;// create servo object to control a servo
void setup() {
  myservo.attach(9,1000,2000); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
//check the diffrent val and print it into the terminal
val=180;
Serial.println(val);
myservo.write(val);
delay(100);
}
