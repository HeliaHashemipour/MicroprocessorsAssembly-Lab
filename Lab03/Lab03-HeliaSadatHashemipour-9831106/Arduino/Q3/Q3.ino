#include <LiquidCrystal.h>
#include <Keypad.h>

#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11

LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'o','0','=','+'}
};

byte rowPins[ROWS]={23,25,27,29};
byte colsPins[COLS]={31,33,35,37};
char str[20];
char str_1[20];
char str_2[20];
char oper;
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colsPins,ROWS,COLS);
int op1,op2;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  char key =keypad.getKey();
  lcd.setCursor(0,0);
  if(strcmp(str,NULL)==0){
    str[0]=key;  
  }
  else if(key!='='){
    strncat(str,&key,1);
    lcd.print(str);
     if(key=='/' ||key=='*' ||key=='-' ||key=='+')
     {
      if(oper==NULL){
        oper=key;
        op1=atoi(str_1);
      }
  }
  else{
    if(oper==NULL){
      if(strcmp(str_1,NULL)==0){
        str_1[0]=key;
      }
      else
       strncat(str_1,&key,1);
    }
    else{
      if(strcmp(str_2,NULL)==0){
        str_2[0]=key;
      }
      else
       strncat(str_2,&key,1);
      
     }
  }
}
else if(key=='='){
  op2=atoi(str_2); 
  lcd.setCursor(0, 1);
   switch(oper){
    case('-'):
      lcd.print (op1-op2);
      break;
    case('+'):
     lcd.print(op1+op2);
     break;
    case('*'):
      lcd.print(op1*op2);
      break;
    case('/'):
      lcd.print((float)op1/op2);
     break;
     }
}

  
}
