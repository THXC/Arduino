// Franzis Arduino
// Arduino Serial.available Funktion

byte eingabe, ausgabe;


void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Serial.available Funktion"); 
   Serial.println(); 
}


void loop()
{    

   if (Serial.available() > 0) 
   {
      eingabe=Serial.read();
      Serial.print("Ich habe folgendes Zeichen empfangen: ");
      ausgabe=char(eingabe);
      Serial.println(eingabe);
   }     
}



