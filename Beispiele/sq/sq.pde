// Franzis Arduino
// Arduino pow(base,exponent) Funktion

int Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino pow(base,exponent) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=pow(10,5);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


