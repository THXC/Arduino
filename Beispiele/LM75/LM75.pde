// Franzis Arduino
// Auslesen eines LM75 I²C- Bus Temperatursensors

#include <Wire.h>

#define LM75 (0x90 >> 1)   // 7Bit Adresse LM75 7-Bit Adresse

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("LM75 IIC-Bus Temperatursensor");
}


void loop()
{
    byte msb,lsb=0;
    float Grad=0;

    Wire.beginTransmission(LM75);
    Wire.send(0x00);
    Wire.endTransmission();
  
    Wire.requestFrom(LM75, 2);       
    while(Wire.available() < 2);     
    msb = Wire.receive();     
    lsb = Wire.receive();

    if(msb<0x80)
    {
       Grad=((msb*10)+(((lsb&0x80)>>7)*5));
    }
    else
    {
       Grad=((msb*10)+(((lsb&0x80)>>7)*5));
       Grad=-(2555.0-Grad);
    }
    
    Grad=Grad/10;
    
    Serial.print(Grad);
    Serial.println(" Grad");
        
    delay(1000);
     
}






