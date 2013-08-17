/*
  Blink
  
  Verwendet die LED "L" auf der Arduino/ Freeduino Platine
  
*/

int ledPin =  13;    // LED ist am Digital pin 13 angeschlossen

// Die Setuproutine konfiguriert unseren Digitalport
// Diese Routine wird nur einmal beim Programmstart ausgeführt!
void setup()
{                
  // Der Port wird als Ausgang konfiguriert
  pinMode(ledPin, OUTPUT);     
}


// Das Hauptprogramm ist eine Endlosscheleife
void loop()                     
{
  digitalWrite(ledPin, HIGH);   // LED einschalten
  delay(1000);                  // Eine Sekunde warten
  digitalWrite(ledPin, LOW);    // LED ausschalten
  delay(1000);                  // Eine Sekunde warten
}


