// Franzis Arduino
// Lüftersteuerung

int LED=13;
int LDR=0;
int Poti=1;
int cnt=0;
int Flag=0;

void setup()
{
  pinMode(LED,OUTPUT);
}

void loop() 
{

  if(analogRead(LDR)<analogRead(Poti))cnt++;
  if(analogRead(LDR)>analogRead(Poti))cnt=0;
    
  if(cnt>300)
  {
    digitalWrite(LED,HIGH);
    do
    {
      delay(100);
    }while(analogRead(LDR)<analogRead(Poti));
    cnt=0;
    delay(10000);
    digitalWrite(LED,LOW);
  }
  
  delay(10);
  
}



