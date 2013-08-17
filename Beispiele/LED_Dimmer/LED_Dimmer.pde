// Franzis Arduino
// LED Dimmer

int helligkeit=0;
int SW1=3;
int SW2=2;
int LED=11;


void setup()
{
  pinMode(SW1,INPUT);
  digitalWrite(SW1,HIGH);  
  pinMode(SW2,INPUT);
  digitalWrite(SW2,HIGH);
}

void loop()
{

  if(!digitalRead(SW1)&&digitalRead(SW2)) 
  {
    if(helligkeit<255)helligkeit++;
    analogWrite(LED,helligkeit);
    delay(10);
  }
  else if(digitalRead(SW1)&&!digitalRead(SW2))
  {
    if(helligkeit!=0)helligkeit--;
    analogWrite(LED,helligkeit);
    delay(10);
  }
  
  
}






