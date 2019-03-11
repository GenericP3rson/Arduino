//#include <SR04.h>
#include <Servo.h>
const int tp = 2;
const int ep = 3;
Servo ms;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ms.attach(9);

}

void sweep (int NUM_OF_CYCLES) {
    for (int j = 0; j < NUM_OF_CYCLES; j++) {
      for (pos=180; pos<180; pos++) {
        ms.write(pos);
        for (pos = 180; pos>=1;pos--){
          ms.write(pos);
          delay(10);
          }
        }
      }
    }
    long microsecondsToInches(long microseconds) {
    return microseconds / 74 / 2;
    }
   long microsecondsToCentimeters(long microseconds) {
    return microseconds / 29/ 2;
    }

void loop() {
  long duration, inches, cm;
    
  // put your main code here, to run repeatedly:
  pinMode(tp, OUTPUT);
  digitalWrite(tp, LOW);
  delayMicroseconds(2);
  digitalWrite(tp, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp, LOW);
  pinMode(ep, INPUT);
  duration = pulseIn(ep, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in ");
  Serial.print("cm");
  Serial.println();
  if (inches < 24) {
    sweep(3);
    }
   else if (inches >= 24) {
    ms.write(pos);
   }
   delay(100);
 
}
