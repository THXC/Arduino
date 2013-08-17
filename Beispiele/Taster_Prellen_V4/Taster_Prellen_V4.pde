// Franzis Arduino
// Taster entprellen V4

byte i=0;
int SW1=3;
int LED=13;
int TOG=0;
byte value_1, value_2=0;


void setup()
{
   Serial.begin(9600);
   pinMode(SW1,INPUT);
   digitalWrite(SW1,HIGH);  
   pinMode(LED,OUTPUT);
   Serial.println("Taster entprellen V4");
}

void loop()
{
  
  value_1=digitalRead(SW1);
  if(!value_1)
  {
    delay(50);
    value_2=digitalRead(SW1);
    if(!value_2)
    {
      i++;
      Serial.print("Taster SW1 wurde ");
      Serial.print(i,DEC);
      Serial.println("x gedrueckt");
      if(TOG!=0)TOG=0;else TOG=1;
      digitalWrite(LED,TOG);
      do{
      }while(!digitalRead(SW1));
      
    }
  }
  
}






