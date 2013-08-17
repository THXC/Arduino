// Franzis Arduino
// Arduino map(x, fromLow, fromHigh, toLow, toHigh) Funktion

int x,Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Map Funktion"); 
   Serial.println(); 
}


void loop()
{    
    for(x=0;x<20;x++)
    {
      Erg=map(x,0,20,5,15);
      Serial.print(Erg);
      Serial.println();
    }

   while(1);
}


