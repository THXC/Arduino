/*Arduino UsserInterface Ethernet test Pprogram*/
/*With this simple program u understand how to write programs and communicate your arduino board over Ethernet interface*/
/*THXC*/
//ver. 2.0.1

#include <SPI.h>
#include <Ethernet.h>

#define A 40
#define B 41
#define C 42
#define D 43

int r1 = 30;
int r2 = 31;
int r3 = 32;
int r4 = 33;
int r5 = 34;
int r6 = 35;

byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x86, 0x3F};
byte ip[] = {192, 168, 178, 199};
byte gateway[] = {192, 168, 178, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(8496);

String readString = "";
int t1 = 200;
int t2 = 150;


void setup()
{
	Ethernet.begin(mac, ip, gateway, subnet);
	delay(1000);
	
	/*The Kanal A B C D */
	
	pinMode(A, OUTPUT);
	digitalWrite(A, LOW);
	
	pinMode(B, OUTPUT);
	digitalWrite(B, LOW);
	
	pinMode(C, OUTPUT);
	digitalWrite(C, LOW);
	
	pinMode(D, OUTPUT);
	digitalWrite(D, LOW);
	
	/*The On OFF Functions*/
	
	pinMode(r1, OUTPUT);
	digitalWrite(r1, LOW);
	
	pinMode(r2, OUTPUT);
	digitalWrite(r2, LOW);
	
	
	
	pinMode(r3, OUTPUT);
	digitalWrite(r3, LOW);
	
	pinMode(r4, OUTPUT);
	digitalWrite(r4, LOW);
	
	
	
	pinMode(r5, OUTPUT);
	digitalWrite(r5, LOW);
	
	pinMode(r6, OUTPUT);
	digitalWrite(r6, LOW);
	
	
	
	Serial.begin(115200);
}

void loop()
{
	
	/*main program here on/off*/
	
	EthernetClient client = server.available();
	if (client)
	{
		while (client.connected())
		{
			if (client.available())
			{
				char c = client.read();
				readString += c;
				
				if (c == '0')
				{
					ON1();
				}

				if (c == '1')
				{
					OFF1();
				}
				
				if (c == '2')
				{
					ON2();
				}
				if (c == '3')
				{
					OFF2();
				}
				if (c == '4')
				{
					ON3();
				}
				if (c == '5')
				{
					OFF3();
				}
				if (c == '6')
				{
					ON4();
				}
				if (c == '7')
				{
					OFF4();
				}
				if (c == '8')
				{
					ON5();
				}
				if (c == '9')
				{
					OFF5();
				}
				if (c == 'q')
				{
					ON6();
				}
				if (c == 'w')
				{
					OFF6();
				}
				if (c == '!')
				{
					ON7();
				}
				if (c == 'e')
				{
					OFF7();
				}
				if (c == 'r')
				{
					ON8();
				}
				if (c == '$')
				{
					OFF8();
				}
				if (c == '%')
				{
					ON9();
				}
				if (c == '&')
				{
					OFF9();
				}
				if (c == '/')
				{
					ON10();
				}
				if (c == '{')
				{
					OFF10();
				}
				if (c == '(')
				{
					ON11();
				}
				if (c == '[')
				{
					OFF11();
				}
				if (c == ')')
				{
					ON12();
				}
				if (c == ']')
				{
					OFF12();
				}
			}
		}
	}
}


/*the on function for remote control*/

/*kanal A*/

void ON1()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r1,HIGH);
		delay(t2);
		digitalWrite(r1,LOW);
		delay(t1);
	}
	digitalWrite(A,LOW);
}

void OFF1()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r2,HIGH);
		delay(t2);
		digitalWrite(r2,LOW);
		delay(t1);
	}
	digitalWrite(A,LOW);
}

void ON2()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r3,HIGH);
		delay(t2);
		digitalWrite(r3,LOW);
		delay(t1);
	}
	digitalWrite(A,LOW);
}

void OFF2()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r4,HIGH);
		delay(t2);
		digitalWrite(r4,LOW);
		delay(t1);
	}
	digitalWrite(A,LOW);
}

void ON3()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r5,HIGH);
		delay(t2);
		digitalWrite(r5,LOW);
		delay(t1);
	}
	digitalWrite(A,LOW);
}

void OFF3()
{
	digitalWrite(A,HIGH);
	{
		delay(t1);
		digitalWrite(r6,HIGH);
		delay(t2);
		digitalWrite(r6,LOW);
	}
	digitalWrite(A,LOW);
}

/*kanla B*/

void ON4()
{
	digitalWrite(B,HIGH);
	{
		delay(t1);
		digitalWrite(r1,HIGH);
		delay(t2);
		digitalWrite(r1,LOW);
		delay(t1);
	}
	digitalWrite(B,LOW);
}

void OFF4()
{
	digitalWrite(B,HIGH);
	{
		delay(t1);
		digitalWrite(r2,HIGH);
		delay(t2);
		digitalWrite(r2,LOW);
		delay(t1);
	}
	digitalWrite(B,LOW);
}

void ON5()
{
	digitalWrite(B,HIGH);
		{
		delay(t1);
		digitalWrite(r3,HIGH);
		delay(t2);
		digitalWrite(r3,LOW);
		delay(t1);
	}
	digitalWrite(B,LOW);
}

void OFF5()
{
	digitalWrite(B,HIGH);
	{
		delay(t1);
		digitalWrite(r4,HIGH);
		delay(t2);
		digitalWrite(r4,LOW);
		delay(t1);
	}
	digitalWrite(B,LOW);
}

void ON6()
{
	digitalWrite(B,HIGH);
	{
		delay(t1);
		digitalWrite(r5,HIGH);
		delay(t2);
		digitalWrite(r5,LOW);
		delay(t1);
	}
	digitalWrite(B,LOW);
}

void OFF6()
{
	digitalWrite(B,HIGH);
	{
		delay(t1);
		digitalWrite(r6,HIGH);
		delay(t2);
		digitalWrite(r6,LOW);
	}
	digitalWrite(B,LOW);
}

/*kanal C*/

void ON7()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r1,HIGH);
		delay(t2);
		digitalWrite(r1,LOW);
		delay(t1);
	}
	digitalWrite(C,LOW);
}

void OFF7()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r2,HIGH);
		delay(t2);
		digitalWrite(r2,LOW);
		delay(t1);
	}
	digitalWrite(C,LOW);
}

void ON8()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r3,HIGH);
		delay(t2);
		digitalWrite(r3,LOW);
		delay(t1);
	}
	digitalWrite(C,LOW);
}

void OFF8()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r4,HIGH);
		delay(t2);
		digitalWrite(r4,LOW);
		delay(t1);
	}
	digitalWrite(C,LOW);
}

void ON9()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r5,HIGH);
		delay(t2);
		digitalWrite(r5,LOW);
		delay(t1);
	}
	digitalWrite(C,LOW);
}

void OFF9()
{
	digitalWrite(C,HIGH);
	{
		delay(t1);
		digitalWrite(r6,HIGH);
		delay(t2);
		digitalWrite(r6,LOW);
	}
	digitalWrite(C,LOW);
}

/*kanal D*/

void ON10()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r1,HIGH);
		delay(t2);
		digitalWrite(r1,LOW);
		delay(t1);
	}
	digitalWrite(D,LOW);
}

void OFF10()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r2,HIGH);
		delay(t2);
		digitalWrite(r2,LOW);
		delay(t1);
	}
	digitalWrite(D,LOW);
}

void ON11()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r3,HIGH);
		delay(t2);
		digitalWrite(r3,LOW);
		delay(t1);
	}
	digitalWrite(D,LOW);
}

void OFF11()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r4,HIGH);
		delay(t2);
		digitalWrite(r4,LOW);
		delay(t1);
	}
	digitalWrite(D,LOW);
}

void ON12()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r5,HIGH);
		delay(t2);
		digitalWrite(r5,LOW);
		delay(t1);
	}
	digitalWrite(D,LOW);
}

void OFF12()
{
	digitalWrite(D,HIGH);
	{
		delay(t1);
		digitalWrite(r6,HIGH);
		delay(t2);
		digitalWrite(r6,LOW);
	}
	digitalWrite(D,LOW);
}