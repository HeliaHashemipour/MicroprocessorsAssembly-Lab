#define LED1 6
#define LED2 5
#define LED3 4
#define LED4 3
#define LED5 2
#define LED6 1
#define LED7 0

const long interval_delay = 300;

void setup() {
  // put your setup code here, to run once:
 pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);
 pinMode(LED3,OUTPUT);
 pinMode(LED4,OUTPUT);
 pinMode(LED5,OUTPUT);
 pinMode(LED6,OUTPUT);
 pinMode(LED7,OUTPUT);
 //INPUTS (SWITCHES)
 pinMode(12,INPUT);//button1
 pinMode(11,INPUT);//button2
 pinMode(10,INPUT);//button3
}
 
void loop() {
  // put your main code here, to run repeatedly:
//PULL UP CIRCUIT
  if(digitalRead(12)==LOW){//button1
    //at first LEDs are OFF(LOW)
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
   digitalWrite(LED4,LOW);
   digitalWrite(LED5,LOW);
   digitalWrite(LED6,LOW);
   digitalWrite(LED7,LOW);
   //START
   digitalWrite(LED1,HIGH);
   delay(interval_delay);//DELAY FOR 0.3SEC
   digitalWrite(LED2,HIGH);
   delay(interval_delay);
   digitalWrite(LED3,HIGH);
   delay(interval_delay);
   digitalWrite(LED4,HIGH);
   delay(interval_delay);
   digitalWrite(LED5,HIGH);
   delay(interval_delay);
   digitalWrite(LED6,HIGH);
   delay(interval_delay);
   digitalWrite(LED7,HIGH);
   delay(1000);
  }
else if(digitalRead(11)==LOW){//button2
   //at first LEDs are low
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
   digitalWrite(LED4,LOW);
   digitalWrite(LED5,LOW);
   digitalWrite(LED6,LOW);
   digitalWrite(LED7,LOW);
  for(int i=0;i< strlen("helia");i++){
   digitalWrite(LED1,HIGH);
   digitalWrite(LED2,HIGH);
   digitalWrite(LED3,HIGH);
   digitalWrite(LED4,HIGH);
   digitalWrite(LED5,HIGH);   
   digitalWrite(LED6,HIGH);
   digitalWrite(LED7,HIGH);    
   delay(interval_delay);
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
   digitalWrite(LED4,LOW);
   digitalWrite(LED5,LOW);
   digitalWrite(LED6,LOW);
   digitalWrite(LED7,LOW);
   delay(interval_delay);
  }
   digitalWrite(LED1,HIGH);
   digitalWrite(LED2,HIGH);
   digitalWrite(LED3,HIGH);
   digitalWrite(LED4,HIGH);
   digitalWrite(LED5,HIGH);
   digitalWrite(LED6,HIGH);
   digitalWrite(LED7,HIGH);
   delay(2000);
}
  else if(digitalRead(10)==LOW){//button3
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
   digitalWrite(LED3,LOW);
   digitalWrite(LED4,LOW);
   digitalWrite(LED5,LOW);
   digitalWrite(LED6,LOW);
   digitalWrite(LED7,LOW);
  
}
}
  
