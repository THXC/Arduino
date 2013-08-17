#include <Wire.h>

#define exp_0 56// Adresse des PCF8574 hier: PCF8574AP mit allen 3 Adress-Pins nach Masse
#define exp_1 57

void setup()
{
	Wire.begin();
}

void loop() 
{
	Wire.beginTransmission(exp_0); //?ffnen der Verbindung+
	{
		Wire.write(B10101010); //Schreiben des Bytes. Jede Null stellt ein Bit an den Pins des PCF8574 dar (Auch m?glich in Hex Schreibweise)
		Wire.endTransmission(); //Schlie?en der Verbindung
		delay(85);
		Wire.beginTransmission(exp_0);
		Wire.write(B01010101); //Schreiben des Bytes. Jede Null stellt ein Bit an den Pins des PCF8574 dar (Auch m?glich in Hex Schreibweise)
		Wire.endTransmission(); //Schlie?en der Verbindung
		delay(85);
	}
	Wire.beginTransmission(exp_1); 
	{
		Wire.write(B10101010);
		Wire.endTransmission(); 
		delay(85);
		Wire.beginTransmission(exp_1);
		Wire.write(B01010101);
		Wire.endTransmission();
		delay(85);
	}
}