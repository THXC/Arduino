// Franzis Arduino
// Arduino Funktionen

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Funktionen"); 
   Serial.println(); 
}


void loop()
{
   int Erg;
   Erg=Addition(12,55);
   Serial.print("Die Summe aus 12 + 55 = ");    
   Serial.println(Erg);
   
   while(1);
}


int Addition(int x, int y)
{
   int sum;
   sum=x+y;
   return sum;    
}


