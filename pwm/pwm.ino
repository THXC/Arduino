


int ledPin1 = 9;    // LED connected to digital pin 9
int ledPin2 = 3;
int fadeValue = 0;

void setup()  {
	// nothing happens in setup
	Serial.begin(115200);
	Serial.println("RDY");
}

void loop()  {
	// fade in from min to max in increments of 5 points:
	for(fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
		// sets the value (range from 0 to 255):
		Serial.print("+ ");
		analogWrite(ledPin1, fadeValue);
		analogWrite(ledPin2, fadeValue);
		Serial.println(fadeValue);
		// wait for 30 milliseconds to see the dimming effect
		delay(100);
	}

	// fade out from max to min in increments of 5 points:
	for(fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
		// sets the value (range from 0 to 255):
		Serial.print("- ");
		analogWrite(ledPin1, fadeValue);
		analogWrite(ledPin2, fadeValue);
		Serial.println(fadeValue);
		// wait for 30 milliseconds to see the dimming effect
		delay(100);
	}
}