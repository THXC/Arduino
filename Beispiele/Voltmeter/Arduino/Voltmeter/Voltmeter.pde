// Franzis Arduino
// 6-Kanal Voltmeter

int LED=13;
char startbyte=0;
int highbyte=0;
int lowbyte=0;
int adc_raw[6];
int adc_cnt=0;
int cnt=0;
int crc=0;


void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);    
}


void loop()
{

  startbyte=Serial.read();
  if(startbyte==42)
  {
    digitalWrite(LED,HIGH);
    delay(50);
    digitalWrite(LED,LOW);
    delay(50);    
    Serial.flush();
    
    for(cnt=0;cnt<6;cnt++)
    {
      adc_raw[cnt]=analogRead(adc_cnt);     
      adc_cnt++;       
    }
    adc_cnt=0;
    
    for(cnt=0;cnt<6;cnt++)
    {
      highbyte=adc_raw[cnt]/256;
      lowbyte=adc_raw[cnt]%256;
      Serial.write(highbyte);
      Serial.write(lowbyte);     
    }
    
    crc=170^highbyte^lowbyte;
    Serial.write(crc);
  }   
  
}



