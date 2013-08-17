// Franzis Arduino
// RTC 

int cnt, Sekunde, Minute, Stunde=0;
int LED=13;

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  
  // Zeitvorgabe
  Sekunde=13;
  Minute=10;
  Stunde=0;
}

void loop() 
{

  cnt++;
  if(cnt==50)digitalWrite(LED,LOW);
  
  if(cnt==100)
  {
    digitalWrite(LED,HIGH);
    Serial.print(Stunde);
    Serial.print(":");
    Serial.print(Minute);
    Serial.print(":");
    Serial.println(Sekunde);
    Sekunde++; 
    if(Sekunde==60)
    {
      Sekunde=0;
      Minute++;     
      if(Minute==60)
      {
        Minute=0;
        Stunde++;        
        if(Stunde==24)
        {
          Stunde=0;
        }
      }
    }    
    cnt=0;
  }    
  delay(10);
}


