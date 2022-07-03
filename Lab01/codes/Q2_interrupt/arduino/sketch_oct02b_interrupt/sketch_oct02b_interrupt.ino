#define LED1 6
#define LED2 5
#define LED3 4
#define LED4 3
#define LED5 2
#define LED6 1
#define LED7 0

volatile boolean flag1=false;
volatile boolean flag2=false;
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

  pinMode(18,INPUT);
  pinMode(19,INPUT);
  pinMode(20,INPUT);
  //for interrupt we have to use this function
  attachInterrupt(digitalPinToInterrupt(18), switch1Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(19), switch2Pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(20), switch3Pressed, FALLING);
}

void switch1Pressed(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    /*can use below loop instead of upper code
     for (int i=0;i<7;i++){
     digitalWrite(i,LOW);
    * }
     */
    flag1=true;
}

void switch2Pressed(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
  /*can use below loop instead of upper code
    * for (int i=0;i<7;i++){
    * digitalWrite(i,LOW);
    * }
    */
    flag2=true;
}
void switch3Pressed(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
      /*can use below loop instead of upper code
    * for (int i=0;i<6;i++){
    * digitalWrite(i,LOW);
    * }
    */
}


void loop() {
  // put your main code here, to run repeatedly:
  
  if(flag1==true){
    digitalWrite(LED1,HIGH);
    delay(interval_delay);
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
    delay(interval_delay);
    flag1=false;
  }

  if(flag2==true){
    for (int i=0;i<strlen("helia");i++){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, HIGH);

      delay(interval_delay);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      delay(interval_delay);
      
    }
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, HIGH);
      flag2=false;
  }
}
