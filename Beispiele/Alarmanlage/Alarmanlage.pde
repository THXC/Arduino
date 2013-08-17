// Franzis Arduino
// Alarmanlage

int LED=13;
int LDR=0;
int Poti=1;
int Speaker=8;
int cnt=0;
int value,Schwelle=0;


void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(Speaker,OUTPUT);  
  value=analogRead(LDR);
}

void loop() 
{

  cnt++;
  if(cnt>1000)
  {
    cnt=0;
    value=analogRead(LDR);
  }

  Schwelle=(analogRead(Poti)/10);
  if(value>(analogRead(LDR)+Schwelle)||value<analogRead(LDR-Schwelle))
  {
   digitalWrite(LED,HIGH);
   tone(Speaker,500);
   delay(2500);
   noTone(Speaker);
   digitalWrite(LED,LOW);   
   value=analogRead(LDR);
  }
  
   delay(10);
   
}



