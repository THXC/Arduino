// Franzis Arduino
// Arduino sqrt(x) Funktion

int Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino sqrt(x) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=sqrt(9);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


