#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("Angela");
  delay(300);
  lcd.setCursor(2,1);
  lcd.print("Jackson");
  delay(300);
  lcd.clear();
  lcd.blink();
  delay(400);
  lcd.setCursor(7,1);
  delay(300);
  lcd.noBlink();
  lcd.cursor();
  delay(400);
  lcd.noCursor();
  lcd.clear();
}
