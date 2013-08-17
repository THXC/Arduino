// Franzis Arduino
// Arduino min(x,y) Funktion

int x,y,Erg=0;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino min(x,y) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=min(10,55);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


