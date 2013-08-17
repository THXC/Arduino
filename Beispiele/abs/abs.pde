// Franzis Arduino
// Arduino abs(x,y) Funktion

int Erg;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino abs(x,y) Funktion"); 
   Serial.println(); 
}


void loop()
{    
    Erg=abs(3.1415);
    Serial.print(Erg);
    Serial.println();

   while(1);
}


