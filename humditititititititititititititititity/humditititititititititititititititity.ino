#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

int spP = 9;
int len = 1;
#define DHTPIN 5
#define DHTTYPE DHT11
#define COLD A0
#define PERF A1
#define HOT A2
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Tis a test");
  dht.begin();
}

void loop() {
  //digitalWrite(spP, HIGH);
  // put your main code here, to run repeatedly:
  pinMode(spP, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  delay(2000);

  float h = dht.readHumidity();
  float t = dht. readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error! NaN!");
    return;
    }
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.print(" %\t ");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.print(" *C");

   if (t <=20) {
    Serial.println("It's Coooooooooooooooooooooooooooold!!!!");
    digitalWrite(A0, HIGH);
    digitalWrite(spP, HIGH);
    //Turns on
    delay(1000);
    digitalWrite(spP, LOW);
    digitalWrite(A0, LOW);
    //Turns off
    }

    if (20 < t <27) {
      Serial.println(" It's Gooooooooooooooooooooooooooood!!!!");
      digitalWrite(A1, HIGH);
      //Turns on
      delay(2000);
      digitalWrite(A1, LOW);
      }

      if (t >= 27) {
        Serial.println("It's Hoooooooooooooooooooooooooooot!!!!");
        digitalWrite(A2, HIGH);
        digitalWrite(spP, HIGH);
        delay(1000);
        digitalWrite(spP, LOW);
        digitalWrite(A2, LOW);
        }
   
   Serial.print(" %\t ");
   
}
