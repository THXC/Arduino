// Franzis Arduino
// Arduino cos(x) Funktion

float Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino cos(x) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=cos(1.0);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


