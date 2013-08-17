// Franzis Arduino
// Schuluhr 

int cnt, Sekunde, Minute, Stunde=0;
int LED=13;
int Speaker=11;

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(Speaker,OUTPUT);
  
  // Zeitvorgabe
  Stunde=6;
  Minute=59;  
  Sekunde=58;  
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
  
  //  Hier die Läutzeiten
  
  // 1. Stunde
  if(Stunde==7&&Minute==0)Bell();
  if(Stunde==7&&Minute==45)Bell();

  // 2. Stunde
  if(Stunde==7&&Minute==55)Bell();
  if(Stunde==8&&Minute==40)Bell();

  // Frühstueckspause

  // 3. Stunde
  if(Stunde==9&&Minute==0)Bell();
  if(Stunde==9&&Minute==45)Bell();

  // 4. Stunde
  if(Stunde==9&&Minute==55)Bell();
  if(Stunde==10&&Minute==40)Bell();

  // 5. Stunde
  if(Stunde==10&&Minute==50)Bell();
  if(Stunde==11&&Minute==35)Bell();

  // Mittagspause

  // 6. Stunde
  if(Stunde==12&&Minute==05)Bell();
  if(Stunde==12&&Minute==50)Bell();

  // 7. Stunde
  if(Stunde==13&&Minute==0)Bell();
  if(Stunde==13&&Minute==45)Bell();
  
}


void Bell(void)
{
  if(Sekunde<5)
  {
    tone(Speaker,500);
  }
  else
  {
    noTone(Speaker);
  }
}


