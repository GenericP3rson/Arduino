#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

const int rs = 12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int spP = 9;
int len = 1;
#define DHTPIN 6
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
  lcd.begin(16, 2);
  lcd.print("SAJ"); 
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
    lcd.setCursor(4, 0);
   lcd.print(t);
   lcd.setCursor(8, 0);
   lcd.print(h);
    delay(1000);
    digitalWrite(spP, LOW);
    digitalWrite(A0, LOW);
    //Turns off
    }

    if (20 < t <27) {
      Serial.println(" It's Gooooooooooooooooooooooooooood!!!!");
      digitalWrite(A1, HIGH);
      //Turns on
      lcd.setCursor(4, 0);
      lcd.print(t);
      lcd.setCursor(8, 0);
   lcd.print(h);
      delay(2000);
      digitalWrite(A1, LOW);
      }

      if (t >= 27) {
        Serial.println("It's Hoooooooooooooooooooooooooooot!!!!");
        digitalWrite(A2, HIGH);
        digitalWrite(spP, HIGH);
        lcd.setCursor(4, 0);
   lcd.print(t);
   lcd.setCursor(8, 0);
   lcd.print(h);
        delay(1000);
        digitalWrite(spP, LOW);
        digitalWrite(A2, LOW);
        }
   
   Serial.print(" %\t ");
   
}
