// Franzis Arduino
// Würfelspiel

int i,zahl=0;
int Anz=6;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  randomSeed(6);
}

void loop() 
{
 
  Serial.println("Sende Sie ein Zeichen um zu wuerfeln");
 
  do
  {
  }while(Serial.available()==0); 
  Serial.flush();
    
  Serial.print("Sie haben folgende Zahlen gewuerfelt: ");
    
  for(i=0;i<Anz;i++)
  {
    zahl=random(6);
    zahl++;
    Serial.print(zahl);
    Serial.print(" ");
  }
  
  Serial.println();
  
}


