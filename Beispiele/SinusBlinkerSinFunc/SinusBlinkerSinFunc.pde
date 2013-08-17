// Franzis Arduino
// Softer Blinker über Sinus Funktion


int ledPin = 11;
float Val;
int led;

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  for (int x=0; x<180; x++) 
  {
    Val = (sin(x*(3.1412/180)));
    led = int(Val*255);
    analogWrite(ledPin, led);
    delay(10);
  }
}
