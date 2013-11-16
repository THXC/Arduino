/*compatibile with arduino nano atmega328*/

#include <Rainbowduino.h>

unsigned int z,x,y;

void setup()
{
	Rb.init(); //initialize Rainbowduino driver
}

void loop()
{
	Layer2();
	Layer21();
	Layer22();
	
	Layer1();
	Layer11();
	Layer12();
	Layer13();
	
}

void Layer1()//zielone
{
	delay(700);
	Rb.clearDisplay();
	for(y=0;y<4;y++)
	{
		Rb.setPixelZXY(0,0,y,0x00FF00);
		Rb.setPixelZXY(0,3,y,0x00FF00);
		Rb.setPixelZXY(3,0,y,0x00FF00);
		Rb.setPixelZXY(3,3,y,0x00FF00);
	}
}

void Layer11()
{
	//delay(1000);
	//Rb.blankDisplay();
	for(x=1;x<3;x++)
	{
		Rb.setPixelZXY(0,x,0,0x00FF00);
		Rb.setPixelZXY(0,x,3,0x00FF00);
		Rb.setPixelZXY(3,x,0,0x00FF00);
		Rb.setPixelZXY(3,x,3,0x00FF00);
	}
}

void Layer12()
{
	for(z=1;z<3;z++)
	{
		Rb.setPixelZXY(z,0,0,0x00FF00);
		Rb.setPixelZXY(z,3,0,0x00FF00);
		Rb.setPixelZXY(z,0,3,0x00FF00);
		Rb.setPixelZXY(z,3,3,0x00FF00);
	}
}

void Layer13()//
{
	delay(700);
	Rb.blankDisplay();
	for(z=1;z<3;z++)
	{
		for(x=1;x<3;x++)
		{
			for(y=1;y<3;y++)
			{
				Rb.setPixelZXY(z,x,y,0x00FF00);
			}
		}
	}
}

void Layer2()//niebieskie
{
	//delay(100);
	//Rb.blankDisplay();
	for(x=1;x<3;x++)
	{
		for(y=1;y<3;y++)
		{
			Rb.setPixelZXY(0,x,y,0x0000FF);
			Rb.setPixelZXY(3,x,y,0x0000FF);
		}
	}
}

void Layer21()
{
	//delay(100);
	//Rb.clearDisplay();
	for(z=1;z<3;z++)
	{
		for(x=1;x<3;x++)
		{
			Rb.setPixelZXY(z,x,0,0x0000FF);
			Rb.setPixelZXY(z,x,3,0x0000FF);
		}
	}
}

void Layer22()
{
	//delay(1000);
	//Rb.blankDisplay();
	for(z=1;z<3;z++)
	{
		for(y=1;y<3;y++)
		{
			Rb.setPixelZXY(z,0,y,0x0000FF);
			Rb.setPixelZXY(z,3,y,0x0000FF);
		}
	}
}