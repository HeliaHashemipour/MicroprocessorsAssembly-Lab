#include <LiquidCrystal.h>
#include <Keypad.h>

#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11

LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
const String name="Helia";
int cursorCoulumn=name.length();
int cursorRow=0;
int cnt=0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();

}

void loop() {
  if(cnt!=12){
    lcd.setCursor(cnt,cursorRow);
    lcd.print(name);
    delay(300);
    lcd.clear();
    cnt++;
  }
  else if(cursorRow==0){
    cursorRow=1;
    cnt=0;
  }
  else if(cursorRow==1){
    cursorRow=0;
    cnt=0;
  }
}
