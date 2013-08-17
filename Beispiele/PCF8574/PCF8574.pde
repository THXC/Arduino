// Franzis Arduino
// Aus- Einlesen eines PCF8574A Portexpanders

#include <Wire.h>

#define addr 0x20

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  
  Serial.println("Alle Ports LOW");
  PCF8574_Write(0x00);
  
  Serial.print("Portzustand: ");
  Serial.println(PCF8574_Read(), BIN);
  delay(1000);
  
  Serial.println("Alle Ports HIGH");
  PCF8574_Write(0xff);
  
  Serial.print("Portzustand: ");
  Serial.println(PCF8574_Read(), BIN);
  delay(1000);
  
}


void PCF8574_Write(byte data )
{
  Wire.beginTransmission(addr);
  Wire.send(data);
  Wire.endTransmission();
}

byte PCF8574_Read() 
{
  byte data;
  Wire.requestFrom(addr, 1);
  if(Wire.available())
  {
    data = Wire.receive();
  }
  return data;
}




