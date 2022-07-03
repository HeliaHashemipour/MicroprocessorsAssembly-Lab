#include <Servo.h>
#include <Keypad.h>

//Setting Keypad configs
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'O','0','=','+'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {31,33, 35,37}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//Servo
Servo servo;  // create servo object to control a servo
  
void setup() {
  servo.attach(9,1000,2000);  // attaches the servo on pin 9 to the servo object
   Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  static String degree="";
  char key = keypad.getKey();  //the key that we get from keypad 
  if(key){
    //if we press the " = " it means that the input is ready
    //we have to subtract the degree with 180 because the input degree 
    //is 180 degree less than output degree.
    //I divided the value into 2 because servo motor can get the value between 0 to 180
    //and our input is in range of 360.
  if(key == '='){
    int value = degree.toInt()  ;
    Serial.println();
    Serial.print("Result: ");
    Serial.println(degree.toInt() - 180);
    value =value/2;
    servo.write(value);
    delay(100);
    degree="";
    
    }if(key >= '0' && key <= '9'){ //if the key input is in range of 0 to 9
                                  //we have to concat it with previous degree value and print it into the terminal
      Serial.print(key);
      degree += key;
    }
  }
}
