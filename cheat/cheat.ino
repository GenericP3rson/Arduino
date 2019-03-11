#include <Servo.h>

Servo myservo; // create servo object to control a servo

const int trigPin = 12;

const int echoPin = 11;

void setup() {

// initialize serial communication:

Serial.begin(9600);

myservo.attach(9); // attaches the servo on pin 9 to the servo object

}

void loop() {

// and the distance result in centimeters:

long duration, cm;

pinMode(trigPin, OUTPUT);

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(20);

digitalWrite(trigPin, LOW);

pinMode(echoPin, INPUT);

duration = pulseIn(echoPin, HIGH);

// convert the time into a distance

cm = microsecondsToCentimeters(duration);

// the condition for the distance
if (cm <= 30) {
for (int i = 0; i <= 180; i++) {
  myservo.write(i);
  delay(10);
  }
for (int i = 180; i >= 0; i--) {
  myservo.write(i);
  delay(10);
  }
} 
Serial.print(cm);

Serial.print("cm");

Serial.println();

delay(100);

}

long microsecondsToCentimeters(long microseconds) {

// The speed of sound is 340 m/s or 29 microseconds per centimeter.

// The ping travels out and back, so to find the distance of the

// object we take half of the distance travelled.

return microseconds / 29 / 2;

}
