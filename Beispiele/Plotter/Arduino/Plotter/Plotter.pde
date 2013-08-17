// Franzis Arduino
// Spannungsplotter

char startbyte=0;
int highbyte=0;
int lowbyte=0;
int adc=0;
int crc=0;


void setup()
{
  Serial.begin(9600);
}


void loop()
{

  startbyte=Serial.read();
  if(startbyte==55)
  {  
    Serial.flush(); 
    adc=analogRead(0);
    highbyte=adc/256;
    lowbyte=adc%256;
    Serial.write(highbyte);
    Serial.write(lowbyte);     
    crc=170^highbyte^lowbyte;
    Serial.write(crc);
  }   
  
}



