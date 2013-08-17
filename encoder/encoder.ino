#include <Encoder.h>

Encoder myEnc(52, 53);
long oldPosition  = -999;

int Enable_A=31;
int Enable_B=41;
int Input_1=32;
int Input_2=33;
int Input_3=42;
int Input_4=43;

int Poti1=A0;
int Poti2=A1;

int val1, val2, targetval1, targetval2;
int maxval=1024;
int minval=0;

 void setup()
 {
	 Serial.begin (115200);
	 pinMode(Enable_A,OUTPUT);
	 pinMode(Enable_B,OUTPUT);
	 pinMode(Input_1,OUTPUT);
	 pinMode(Input_2,OUTPUT);
	 pinMode(Input_3,OUTPUT);
	 pinMode(Input_4,OUTPUT);
 }

 void loop()
 {
	 Motor();
 }

 void Motor_ON()
{
	digitalWrite(Enable_A,HIGH);
	digitalWrite(Enable_B,HIGH);
}

void Motor_OFF()
{
	delay(10);
	digitalWrite(Enable_A,LOW);
	digitalWrite(Enable_B,LOW);
	Motor_Coast();
}

void Motor_Coast()
{
	digitalWrite(Input_1,LOW);
	digitalWrite(Input_2,LOW);
	digitalWrite(Input_3,LOW);
	digitalWrite(Input_4,LOW);
}

void Motor_1_3()
{
	Motor_ON();
	digitalWrite(Input_1,HIGH);
	digitalWrite(Input_2,LOW);
	digitalWrite(Input_3,HIGH);
	digitalWrite(Input_4,LOW);
}

void Motor_2_4()
{
	Motor_ON();
	digitalWrite(Input_1,LOW);
	digitalWrite(Input_2,HIGH);
	digitalWrite(Input_3,LOW);
	digitalWrite(Input_4,HIGH);
}

void Motor()
{
	long newPosition = myEnc.read();
	if(newPosition !=oldPosition)
	{
		oldPosition=newPosition;
		Serial.print("Encoder = ");
		Serial.println(newPosition);
	}
	val1=analogRead(Poti1);
	if ((val1>newPosition)&&(val1>minval))
	{
		Motor_1_3();
	}
	if ((val1<newPosition)&&(val1<maxval))
	{
		Motor_2_4();
	}
	if (val1=newPosition)
	{
		Motor_OFF();
	}
	delay(20);
}	 

/*
void MotorPWM()
{
	val2=analogRead(Poti2);
	targetval2=(val2/4);
	analogWrite(Enable_A,targetval2);
	digitalWrite(Input_1,HIGH);
	digitalWrite(Input_2,LOW);
	Serial.print(" Delay = ");
	Serial.println(targetval2);
}

void Potie()
{
	val1=analogRead(Poti1);
	val2=analogRead(Poti2);
	Serial.print(" Poti ");
	Serial.print(val1);
	Serial.print(" ");
	Serial.println(val2);
}
*/