// Franzis Arduino
// Arduino max(x,y) Funktion

int x,y,Erg=0;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino max(x,y) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=max(10,55);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


