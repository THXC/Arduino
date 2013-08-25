
void setup()
{
	Serial.begin(115200);
	Serial.print("RDY");
	Serial1.begin(115200);
}

void loop()
{
	if(Serial1.available()>0)
	{
		Serial.print("Val ");
		int val = Serial1.parseInt();
		Serial.println(val);
	}
}