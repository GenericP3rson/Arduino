int green = 12;
int red = 13;
int blue = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
int x =0;
int y=0;
int z = 0;

void loop() {
  // put your main code here, to run repeatedly:
  setColor(x, y, z);
  delay(10);
  x+=53;
  y+=6;
  z+=20;
  x = x > 255 ? 0 : x;
  y = y > 255 ? 0 : y;
  z = z > 255 ? 0 : z;
  
}

void setColor(int r, int g, int b) {
  analogWrite(red, r);
  analogWrite(blue, g);
  analogWrite(green, b);
  }
