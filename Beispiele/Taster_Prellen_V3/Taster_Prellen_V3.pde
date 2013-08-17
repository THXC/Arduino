// Franzis Arduino
// Taster entprellen V3

byte i=0;
int SW1=12;

void setup()
{
   Serial.begin(9600);
   pinMode(SW1,INPUT);
   digitalWrite(SW1,HIGH);  
   Serial.println("Taster entprellen V3");
}

void loop()
{

  if(!digitalRead(SW1))
  {
    delay(50);
    if(!digitalRead(SW1))
    {
      do{
      }while(!digitalRead(SW1));
      i++;
      Serial.print("Taster SW1 wurde ");
      Serial.print(i,DEC);
      Serial.println("x gedrueckt");

    }
  }
  
}






