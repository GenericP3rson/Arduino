#include <Servo.h>
int pos = 0;
Servo ser;
void setup() {
  // put your setup code here, to run once:
  ser.attach(9);
}
void loop() {
  // put your main code here, to run repeatedly:
  ser.write(0);
  delay(100);
  ser.write(90);
  delay(100);
  ser.write(180);
  delay(100);
}
