// Franzis Arduino
// Arduino sin(x) Funktion

float Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino sin(x) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=sin(1.0);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


