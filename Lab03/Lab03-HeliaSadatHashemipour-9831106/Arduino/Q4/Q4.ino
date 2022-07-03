#include <LiquidCrystal.h>
#include <Keypad.h>
#define RS_PIN 13
#define EN_PIN 12
#define D4_PIN 8
#define D5_PIN 9
#define D6_PIN 10
#define D7_PIN 11
LiquidCrystal lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
char sh='h';
int cursorCols=0;
int cursorRow=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(sh);
 cursorCols=0;
 cursorRow=0;
  while(cursorCols!=16){
    if(cursorCols%2==0){
      cursorRow=0;
    }
    else{
      cursorRow=1;
    } 
    lcd.clear();
    lcd.setCursor(cursorCols,cursorRow);
    lcd.print(sh);
    cursorCols++;
    delay(100);
  }
}
