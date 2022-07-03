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
const byte COLS=3;
char keys[ROWS][COLS]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte col=0;
byte rowPins[ROWS]={23,25,27,29};
byte colsPins[COLS]={31,33,35};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colsPins,ROWS,COLS);
String correctPass="9831106";
String pass;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
   char key=keypad.getKey();
  lcd.setCursor(col,0);
  if(key){
 
   if(key!='*'){
  lcd.print(key);
  col++;
  pass+=key;
  }
   if(key=='*'){
    lcd.setCursor(0,1);
    if(pass==correctPass){
      lcd.println("correct passsword");
    }
    else{
       lcd.print("wrong passsword");
    }
    pass="";
  }
 
}

}
