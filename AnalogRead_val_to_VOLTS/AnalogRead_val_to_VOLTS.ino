#define przelicznik 0.00485

int Val;

void setup()
{
	/* add setup code here */
}

void loop()
{
	/* add main program code here */
	Potie();
}

void Potie()
{
	Val = analogRead(A1);
	float Volt = analogRead(A1)* przelicznik ;
}
