#include <Servo.h>
#include <Keypad.h>

Servo myservo;
int val;// create servo object to control a servo

void setup() {
   // attaches the servo on pin 9 to the servo object
  myservo.attach(9,1000,2000);
  Serial.begin(9600);
}

void loop() {
  
    Serial.print("Potentiometer: ");
    
    val = analogRead(A0);            // reads the value of the potentiometer(the value is  between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // map( 0 to 1023) into 0 to 180 which is the servo motor get
    Serial.println(val);
    myservo.write(val);
    //the 50 delay  means that our circuits after 0.05s checks that the value of pontasiometer
    delay(50);
}
