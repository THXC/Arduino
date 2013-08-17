// Franzis Arduino
// Taster entprellen V1

byte i=0;
int SW1=12;

void setup()
{
   Serial.begin(9600);
   pinMode(SW1,INPUT);
   digitalWrite(SW1,HIGH);  
   Serial.println("Taster entprellen V1");
}

void loop()
{

  if(!digitalRead(SW1))
  {
    delay(50);
    if(!digitalRead(SW1))
    {
      Serial.println("Taster SW1 wurde gedrueckt");
    }
  }
  
}






