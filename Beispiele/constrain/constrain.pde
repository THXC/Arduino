// Franzis Arduino
// Arduino constrain(x, a, b) Funktion

int x,Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino constrain(x, a, b) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    for(x=0;x<60;x++)
    {
      Erg=constrain(x, 10, 50);
      Serial.print(Erg);
      Serial.println();
    }

   while(1);
}


