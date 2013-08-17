#include <Wire.h>

#define PCF8574AP 0x3F
#define led1	B00000001	//pin 0
#define led2	B00000010	//pin 1
#define led3	B00000100	//pin 2
#define led4	B00001000	//pin 3
#define led5	B00010000	//pin 4
#define led6	B00100000	//pin 5
#define led7	B01000000	//pin 6
#define led8	B10000000	//pin 7
#define ledOFF	B00000000	//pin 8

int x = 600;



void setup()
{

  Wire.begin();

}
void loop()
{
	Wire.beginTransmission(PCF8574AP);
	Wire.write(0xE1);
	delay(350);

	//Wire.write(0x40);
	//delay(500);

	Wire.endTransmission();
}



/*
void loop()
{
	LED1(x);
	LED2(x);
	LED3(x);
	LED4(x);
	LED5(x);
	LED6(x);
	LED7(x);
	LED8(x);

}

void LED1(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led1);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED2(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led2);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED3(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led3);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED4(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led4);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED5(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led5);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED6(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led6);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED7(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led7);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}

void LED8(int time)
{
	Wire.beginTransmission(PCF8574AP);
  {
	  Wire.write(led8);
	  Wire.endTransmission();
	  delay(1000);
	  Wire.beginTransmission(PCF8574AP);
	  Wire.write(ledOFF);
	  Wire.endTransmission();
	  delay(time);
  }
}
*/