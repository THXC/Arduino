// Franzis Arduino
// Das erste Arduino Programm das ich selber abtippe :-)

int ledPin =  13;  // Die LED ist an Pin 13 angeschlosssen

void setup()
{
 Serial.begin(9600); 
 pinMode(ledPin, OUTPUT); 
 Serial.println("Unser erstes Arduino Programm"); 
 Serial.println(); 
}



void loop()
{
  Serial.print("Die Summe aus 5 + 188 lautet ");
  Serial.print(5+188);
  
  while(true)
  { 
   digitalWrite(ledPin, HIGH);   // LED einschalten
   delay(500);                   // warten für 500ms
   digitalWrite(ledPin, LOW);    // LED ausschalten
   delay(500);                   // warten 500ms
   continue; 
  }      
}




