

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	VAL();
}

void VAL()
{
	int val = analogRead(A1);
	Serial.println(val);
}