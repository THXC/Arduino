// Franzis Arduino
// Doppelblitzer


int LED_1=10;
int LED_2=11;
int i=0;
int TOG=0;

void setup()
{
   pinMode(LED_1,OUTPUT);
   pinMode(LED_2,OUTPUT);
}

void loop()
{
  
  for(i=0;i<3;i++)
  {
    if(TOG==0)TOG=HIGH;else TOG=LOW;
    digitalWrite(LED_1,TOG);
    delay(40);
  }
  digitalWrite(LED_1,LOW);
  delay(100);
  
  
  for(i=0;i<3;i++)
  {
    if(TOG==0)TOG=HIGH;else TOG=LOW;
    digitalWrite(LED_2,TOG);
    delay(40);
  }
  digitalWrite(LED_2,LOW);
  delay(100);
  
  
  for(i=0;i<3;i++)
  {
    if(TOG==0)TOG=HIGH;else TOG=LOW;
    digitalWrite(LED_1,TOG);
    delay(40);
  }
  digitalWrite(LED_1,LOW);
  delay(500);
  
}






