// Franzis Arduino
// For

int x;

void setup()
{
 Serial.begin(9600); 
 Serial.println("For Anweisungen"); 
 Serial.println(); 
}


void loop()
{
   
  Serial.println("Schrittweite 1");
  for(x=0;x<11;x++)
  {
     Serial.print("X = ");
     Serial.print(x);
     Serial.println();  
  }

  Serial.println("Schrittweite 2");
  for(x=0;x<11;x=x+2)
  {
     Serial.print("X = ");
     Serial.print(x);
     Serial.println();  
  }
  
  Serial.println("Jetzt zaehlen wir von 10 mit Schrittweite 1 auf 1 herunter");
  for(x=10;x!=0;x--)
  {
     Serial.print("X = ");
     Serial.print(x);
     Serial.println();  
  }

  // Programm Ende!
  while(1);
  
}

