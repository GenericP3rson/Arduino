#include <Servo.h>
Servo ms;
int p = 0;
void setup() {
  // put your setup code here, to run once:
  ms.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (p = 0; p <= 180; p++) {
    ms.write(p);
    delay(0);
    }
   for (p = 180; p >= 0; p--) {
    ms.write(p);
    delay(0);
    }
}
