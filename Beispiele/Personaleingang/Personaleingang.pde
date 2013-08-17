// Franzis Arduino
// Überwachung des Personaleingangs

int i,x=0;
int LED=3;
int SW1=4;
int Empfindlichkeit=0;
int Speaker=3;
int Person=0;

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(Speaker,OUTPUT);
  pinMode(SW1,INPUT);
  digitalWrite(SW1,HIGH);
  randomSeed(1000);
}

void loop() 
{

  Person=(77+analogRead(Empfindlichkeit)/10);
  i=random(1,Person);
  
  while(1)
  {
    if(!digitalRead(SW1))
    {
      delay(50);
      if(!digitalRead(SW1))
      {
        if(x>Person)x=0;
        if(i==x)
        {
          digitalWrite(LED,HIGH);
          tone(Speaker,500,250);
          delay(3000);
          digitalWrite(LED,LOW);
          break;
        }
        
        x++;
        
      }
    }   
  }
}


