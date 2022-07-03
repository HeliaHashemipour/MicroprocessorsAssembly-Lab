#include <Servo.h>
#include <Keypad.h>
//values
int startTime = 0;
bool flag = false;
int timeLimit;
int temperatureLimitation;
bool res=false;
bool cooked = false;
bool inEntered = false;
bool isHeating = false;
bool startCooking = false;

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
//keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//Servo
Servo servo;  // create servo object to control a servo

//return temperature
float analogTemperature(){//float
  float temp = analogRead(A0);
  //convert to celsius
  temp *= 0.48828125;
  //check if cooking is started or not
  if(!startCooking){
  Serial.print("# Current temperature: ");
  Serial.println(temp);
  Serial.print("* req temperature: ");
  Serial.println(temperatureLimitation);
  }
  return temp;
}

//compare the read temperature from input 
bool checkTemperature(){
  delay(300);
  bool check=false;
  if(analogTemperature() >= temperatureLimitation)
      check=true;
  return check;
}

bool checkTime(){
  //convert it to mili second
  int currentTime = millis()/1000; 
  //time distinction
  int value=(currentTime - startTime);
  Serial.print("+ Passed time:" );
  Serial.print(value);
  Serial.println("s" );
  //compare the time distinction & time limit
  if(value >= timeLimit){
    return true;
  }
  return false;
}

void getKeypad(){ //Getting  input from keypad
  char timer[20];
  char temperature[20];
  char key = keypad.getKey();
   if (flag){
    if(strcmp(temperature, NULL) == 0){
      temperature[0] = key;
    }
    else if(key != '='){
      strncat(temperature, &key, 1);
    }
    else  {
      temperatureLimitation = atoi(temperature);
      Serial.print("\n");
      Serial.print("# temp: ");
      Serial.print(temperatureLimitation);
      Serial.println(" C");
      inEntered = true;
      free(timer);
      flag = false;
    }
  } else if(!flag){
    if(strcmp(timer, NULL) == 0)
      timer[0] = key;
      //if press "="
    else if(key != '=')
      strncat(timer, &key, 1);
    else{
      timeLimit = atoi(timer);
      flag = true;
      Serial.print("# time: ");
      Serial.print(timeLimit);
      Serial.println("s");
      free(temperature);
    }
  }
}
   

void setup() {
  pinMode(9, OUTPUT);
  pinMode(12,INPUT);
  Serial.begin(9600);
  servo.attach(13,1000,2000); 
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
 
}


void loop() {
  //if the input is not entered
  if(digitalRead(12)==HIGH){
  if(!inEntered){
    getKeypad();
    digitalWrite(51, LOW);
  }
   else{
    //if the input is entered and the starttime is zer0
  if(!isHeating && startTime == 0){
    //cooker open, so it can start heating
    servo.write(90);
    isHeating = true;
    Serial.println("=> Start Heating");
    //RED LED
    digitalWrite(52, HIGH);
  }
  else if(!cooked && startCooking){//if the food is not cooked 
     //check if cooking time is finished
    if(checkTime()){
      cooked = true;
      servo.write(90);//cooker open
      Serial.println("=> Cooked!!!!");//print cooked
      digitalWrite(52, LOW);//RED LED
      digitalWrite(51, HIGH);
      tone(9, 1000);
      delay(4000);
      noTone(9);
      inEntered = false;
      startCooking = false;
      timeLimit = NULL;
      temperatureLimitation = NULL; 
      startTime = 0;
      delay(100);
    }
  }
  //run while cooker has not reached the input temprature
  else if(checkTemperature()){ 
    //stop increasing cooker's temperature
    Serial.println("=> Heating finished <="); 
    startTime = millis()/1000;
    //cooker close so it can start cooking
    servo.write(0);
    isHeating = false;
    Serial.println("=> Start Cooking <=");
    startCooking = true;
  }
 }
  }
 else{
  digitalWrite(51, LOW);
  digitalWrite(52, LOW);
  Serial.end();
 }
 }
 
 
