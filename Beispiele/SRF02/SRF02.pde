// Franzis Arduino
// Auslesen eines SRF02 Ultraschallsensors von der Fa. Devantech

#include <Wire.h>

#define srfAddress (0xE0 >> 1)  
#define cmdByte 0x00                       
#define rangeByte 0x02                        

byte MSB = 0x00;                        
byte LSB = 0x00;                           

void setup()
{
  Serial.begin(9600);
  Wire.begin();    
  Serial.println("SRF02 Ultraschallsensor");
}

void loop()
{ 
  int rangeData = getRange();            
  Serial.print("Entfernung: ");
  Serial.print(rangeData);
  Serial.println("cm");    
  delay(250);                                 
}

int getRange()
{                               
  
  int range = 0; 
  
  Wire.beginTransmission(srfAddress);           
  Wire.send(cmdByte);                         
  Wire.send(0x51);                             
  Wire.endTransmission();
  
  delay(100);                                 
  
  Wire.beginTransmission(srfAddress);         
  Wire.send(rangeByte);                      
  Wire.endTransmission();
  
  Wire.requestFrom(srfAddress, 2);             
  while(Wire.available() < 2);                 
  MSB = Wire.receive();                 
  LSB = Wire.receive();                     

  range = (MSB << 8) + LSB;          
  
  return(range);                         
}





