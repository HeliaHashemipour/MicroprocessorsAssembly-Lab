#include <Servo.h>
#include <Keypad.h>
Servo myservo; // create servo object to control a servo
String serialInput = "";
int serialDegree = 0;

void setup() {
  myservo.attach(9,1000,2000);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  
  //at first we check that the value is entered in to the terminal.
  //so after that it reads the string and converts it into the integer.
  // because if we enter the negative degree we will come out the range of 0 to 180
  // so we have to substract the intput with 180
  // then divided that into 2.
  //At last we print the result into the terminal
    if(Serial.available() > 0){
    serialInput = Serial.readString();
    Serial.println(serialInput.toInt());
    serialDegree = (180 - serialInput.toInt())/2;
    Serial.println(serialInput.toInt()* (-1));
  }
  myservo.write(serialDegree);

}
