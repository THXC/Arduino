// Franzis Arduino
// Arduino tan(x) Funktion

float Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino tan(x) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=tan(1.0);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


