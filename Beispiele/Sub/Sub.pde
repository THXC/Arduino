// Franzis Arduino
// Arduino Sub-Routinen

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Sub-Routinen"); 
   Serial.println(); 
}


void loop()
{
   Ausgabe1();
   
   Ausgabe2();
   
   while(1);
}


void Ausgabe1()
{
   Serial.println("Ausgabe 1");    
}

void Ausgabe2()
{
   Serial.println("Ausgabe 2");    
}
