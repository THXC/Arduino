// Franzis Arduino
// Arduino Software UART


// Hier wird die Software UART Libraray eingefügt
#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3
#define ledPin 13

// Die Software UART wird konfiguriert
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
byte pinState = 0;

void setup()  
{
  // Konfiguration der Pins
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // Einstellen der Seriellen Baudrate
  mySerial.begin(9600);
}

void loop()
{
  // Jetzt hören wir ob was kommt
  char someChar = mySerial.read();
  // Ausgabe des empfangenen Zeichens
  mySerial.print(someChar);
  // Die LED wird getoggelt  
  toggle(13);

}


void toggle(int pinNum)
{
  digitalWrite(pinNum, pinState); 
  pinState = !pinState;
}

