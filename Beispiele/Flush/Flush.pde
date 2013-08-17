// Franzis Arduino
// Arduino Serial.flush Funktion

byte eingabe[], ausgabe[];


void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Serial.flush Funktion"); 
   Serial.println(); 
}


void loop()
{    

   if (Serial.available() > 0) 
   {
      eingabe[]=Serial.flush();
      Serial.print("Ich habe folgende Zeichen empfangen: ");
      ausgabe[]=char(eingabe[]);
      Serial.println(ausgabe[]);
   }     
}



