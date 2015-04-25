#include <SPI.h>
#include <Ethernet.h>



byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x86, 0x3F};
byte ip[] = {192, 168, 178, 199};
byte gateway[] = {192, 168, 178, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(8496);

String readString = "";
int t1 = 15;
int t2 = 20;

void setup()
{
	pinMode(26, OUTPUT);
	pinMode(27, OUTPUT);
	pinMode(22, OUTPUT);
	digitalWrite(26, LOW);
	digitalWrite(27, LOW);
	digitalWrite(22, LOW);
	Ethernet.begin(mac, ip, gateway, subnet);
	delay(1000);
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
			}
		}
	}
}

void ON1()
{
	digitalWrite(22,HIGH);
	{
		delay(t1);
		digitalWrite(26,HIGH);
		delay(t2);
		digitalWrite(26,LOW);
		delay(t1);
	}
	digitalWrite(22,LOW);
}

void OFF1()
{
	digitalWrite(22,HIGH);
	{
		delay(t1);
		digitalWrite(27,HIGH);
		delay(t2);
		digitalWrite(27,LOW);
		delay(t1);
	}
	digitalWrite(22,LOW);
}