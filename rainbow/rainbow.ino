/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the boardt

//int[] led = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];
int xx = 13;
int y = 2;
int z = 100;

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  while (xx >= y)
  {
  pinMode(xx, OUTPUT);
  xx--;
  }
}

int x = 13;

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
  //x--;
  delay(z);                       // wait for a second
  digitalWrite(x, LOW);    // turn the LED off by making the voltage LOW
  delay(z);       // wait for a second
  x-=2;
  x = x == (y-1) ? 12: x;
  x = x == (y-2) ? 13: x;
}
