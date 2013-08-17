// Franzis Arduino
// Einschaltverzögerung

int SW1=12;
int value_1, value_2=0;
int LED=13;
byte Flag=0;
int i=0;

void setup()
{
   pinMode(SW1,INPUT);
   digitalWrite(SW1,HIGH);  
   pinMode(LED,OUTPUT);
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
      Flag=1;
      do{
      }while(!digitalRead(SW1));    
    }   
  }
  
  if(Flag==1)i++;
  if(i>3000)
  {
    digitalWrite(LED,HIGH);
    while(1);
  }
  
  delay(1);
  
}






