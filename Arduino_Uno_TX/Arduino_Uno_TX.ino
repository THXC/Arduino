

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	sendSample(sample);
}

void sendSample(int sample)
{
  byte low = sample & 0x1F ; // bottom 5 bits: 000xxxxx
  byte high = (sample >> 5) | 0xE0 ; // top 5 bits tagged with 111xxxxx
  Serial.write (high) ;
  Serial.write (low) ;
}