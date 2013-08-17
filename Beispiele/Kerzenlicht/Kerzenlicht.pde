// Franzis Arduino
// Kerzenlicht

int led_gelb1 = 9;
int led_rot = 10;
int led_gelb2 = 11;


void setup()
{
  pinMode(led_gelb1, OUTPUT);
  pinMode(led_rot, OUTPUT);
  pinMode(led_gelb2, OUTPUT);
}

void loop()
{
  analogWrite(led_gelb1, random(120)+135);
  analogWrite(led_rot, random(120)+135);
  analogWrite(led_gelb2, random(120)+135);
  delay(random(100));
}
