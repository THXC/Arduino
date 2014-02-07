/*Arduino UsserInterface Ethernet test Pprogram*/
/*With this simple program u understand how to write programs and communicate your arduino board over Ethernet interface*/
/*THXC*/

#include <SPI.h>
#include <Ethernet.h>



byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x86, 0x3F};
byte ip[] = {192, 168, 178, 199};
byte gateway[] = {192, 168, 178, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(8496);

String readString = String(30);


void setup()
{
	Ethernet.begin(mac, ip, gateway, subnet);
	delay(1000);
	Serial.begin(115200);
}

void loop()
{
	EthernetClient client = server.available();
	if (client.connected())
	{
		Serial.println("Connected");
		client.println("Connected");
	}
	else 
	{
		Serial.println("Not Connected");
	}
}