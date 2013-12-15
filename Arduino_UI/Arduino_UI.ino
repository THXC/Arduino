#include <Servo.h>

int pos = 0;
int PWM = 13;

Servo myservo;
String readString;

void setup()																//setup
{
	pinMode(40, OUTPUT);													//pin set to OUTPUT
	pinMode(PWM, OUTPUT);
	
	myservo.attach(3);	
	
	Serial.begin(115200);													//serial port is set to val
	Serial.println("TEST PROGRAM By THXC");									//print msg on port
}

void loop()																	//loop
{
	
	while (Serial.available()) {											//see if serial is available
		delay(3);															//a few seconds delay
		char aChar = Serial.read();											// convert serial read to aChar
		readString += aChar;												// read the string
	}

	if (readString.length() >0) 
	{																		//and here we be starting
		Serial.println(readString);

		if (readString.indexOf("40ON") >=0)									//if serial read receives 40ON µC will set this pin to High
		{
			digitalWrite(40, HIGH);
			Serial.print("\tPin 40 is ON\t");
		}

		if (readString.indexOf("40OFF") >=0)									//to off
		{
			digitalWrite(40, LOW);
			Serial.print("\tPin 40 is OFF\t");
		}
		
		if (readString.indexOf("40T") >=0)									
		{
			digitalWrite(40,HIGH);
			delay(150);
			digitalWrite(40,LOW);
			Serial.print("\tPin 40 is T\t");
		}
		
																			//PWM
		if (readString.indexOf("125PWM") >=0)
		{
			analogWrite(PWM, 32);
			Serial.print("\tPWM set to 12,5%\t");
		}
		
		if (readString.indexOf("25PWM") >=0)
		{
			analogWrite(PWM, 64);
			Serial.print("\tPWM set to 25%\t");
		}
		
		if (readString.indexOf("375PWM") >=0)
		{
			analogWrite(PWM, 96);
			Serial.print("\tPWM set to 37,5%\t");
		}
		
		if (readString.indexOf("50PWM") >=0)
		{
			analogWrite(PWM, 128);
			Serial.print("\tPWM set to 50%\t");
		}
		
		if (readString.indexOf("625PWM") >=0)
		{
			analogWrite(PWM, 160);
			Serial.print("\tPWM set to 62,5%\t");
		}
		
		if (readString.indexOf("75PWM") >=0)
		{
			analogWrite(PWM, 192);
			Serial.print("\tPWM set to 75%\t");
		}
		
		if (readString.indexOf("875PWM") >=0)
		{
			analogWrite(PWM, 224);
			Serial.print("\tPWM set to 87,5%\t");
		}
		
		if (readString.indexOf("100PWM") >=0)
		{
			analogWrite(PWM, 255);
			Serial.print("\tPWM set to 100%\t");
		}
		
		if (readString.indexOf("PWMOFF") >=0)
		{
			digitalWrite(PWM, LOW);
			Serial.print("\tPWM OFF\t");
		}
								
		readString="";
	}
}