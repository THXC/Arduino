/*Arduino UsserInterface Ethernet test Pprogram*/
/*With this simple program u understand how to write programs and communicate your arduino board over Ethernet interface*/
/*THXC*/
//ver. 1.01

#include <SPI.h>
#include <Ethernet.h>



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
	pinMode(49, OUTPUT);
	digitalWrite(49, LOW);
	pinMode(48, OUTPUT);
	digitalWrite(48, LOW);
	pinMode(47, OUTPUT);
	digitalWrite(47, LOW);
	pinMode(46, OUTPUT);
	digitalWrite(46, LOW);
	pinMode(45, OUTPUT);
	digitalWrite(45, LOW);
	pinMode(44, OUTPUT);
	digitalWrite(44, LOW);
	pinMode(43, OUTPUT);
	digitalWrite(43, LOW);
	pinMode(42, OUTPUT);
	digitalWrite(42, LOW);
	pinMode(41, OUTPUT);
	digitalWrite(41, LOW);
	pinMode(40, OUTPUT);
	digitalWrite(40, LOW);
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

void ON1()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(40,HIGH);
		delay(t2);
		digitalWrite(40,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void ON2()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(41,HIGH);
		delay(t2);
		digitalWrite(41,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void ON3()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(42,HIGH);
		delay(t2);
		digitalWrite(42,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void ON4()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(40,HIGH);
		delay(t2);
		digitalWrite(40,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void ON5()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(41,HIGH);
		delay(t2);
		digitalWrite(41,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void ON6()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(42,HIGH);
		delay(t2);
		digitalWrite(42,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void ON7()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(40,HIGH);
		delay(t2);
		digitalWrite(40,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void ON8()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(41,HIGH);
		delay(t2);
		digitalWrite(41,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void ON9()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(42,HIGH);
		delay(t2);
		digitalWrite(42,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void ON10()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(40,HIGH);
		delay(t2);
		digitalWrite(40,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}

void ON11()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(41,HIGH);
		delay(t2);
		digitalWrite(41,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}

void ON12()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(42,HIGH);
		delay(t2);
		digitalWrite(42,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}

/*the off function for remote control*/

void OFF1()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(43,HIGH);
		delay(t2);
		digitalWrite(43,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void OFF2()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(44,HIGH);
		delay(t2);
		digitalWrite(44,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void OFF3()
{
	digitalWrite(46,HIGH);
	{
		delay(t1);
		digitalWrite(45,HIGH);
		delay(t2);
		digitalWrite(45,LOW);
		delay(t1);
	}
	digitalWrite(46,LOW);
}

void OFF4()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(43,HIGH);
		delay(t2);
		digitalWrite(43,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void OFF5()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(44,HIGH);
		delay(t2);
		digitalWrite(44,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void OFF6()
{
	digitalWrite(47,HIGH);
	{
		delay(t1);
		digitalWrite(45,HIGH);
		delay(t2);
		digitalWrite(45,LOW);
		delay(t1);
	}
	digitalWrite(47,LOW);
}

void OFF7()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(43,HIGH);
		delay(t2);
		digitalWrite(43,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void OFF8()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(44,HIGH);
		delay(t2);
		digitalWrite(44,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void OFF9()
{
	digitalWrite(48,HIGH);
	{
		delay(t1);
		digitalWrite(45,HIGH);
		delay(t2);
		digitalWrite(45,LOW);
		delay(t1);
	}
	digitalWrite(48,LOW);
}

void OFF10()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(43,HIGH);
		delay(t2);
		digitalWrite(43,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}

void OFF11()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(44,HIGH);
		delay(t2);
		digitalWrite(44,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}

void OFF12()
{
	digitalWrite(49,HIGH);
	{
		delay(t1);
		digitalWrite(45,HIGH);
		delay(t2);
		digitalWrite(45,LOW);
		delay(t1);
	}
	digitalWrite(49,LOW);
}