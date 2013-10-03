
int val1, val2;

int potie1=A0;
int potie2=A1;

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.print(" Val1 = ");
	val1=analogRead(potie1);
	Serial.println(val1);
	/*Serial.print(" Val 2 = ");
	val2=analogRead(potie2);
	Serial.println(val2);
	delay(1000);
	*/
}