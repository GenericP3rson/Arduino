int a = 9;
int y = 100;
int z = 1000;
int x = 100;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(a, y, x);
  delay(z);
  y+=3;
  z-=100;
  z = z < 0 ? 0 : z;
  y = y > 3000 ? 1000 : y;
}
