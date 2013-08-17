// Franzis Arduino
// Oszilloskop

char startbyte=0;
int highbyte=0;
int lowbyte=0;
int adc[256];
int cnt=0;
int crc=0;


void setup()
{
  Serial.begin(115200);
}


void loop()
{

  startbyte=Serial.read();
  if(startbyte==55)
  {  
    Serial.flush(); 
    
    for(cnt=0;cnt<256;cnt++)
    {
      adc[cnt]=analogRead(0);
    }
    
    for(cnt=0;cnt<256;cnt++)
    {
      highbyte=adc[cnt]/256;
      lowbyte=adc[cnt]%256;
      Serial.write(highbyte);
      Serial.write(lowbyte);     
    }
    
    crc=170^highbyte^lowbyte;
    Serial.write(crc);
  }   
  
}



