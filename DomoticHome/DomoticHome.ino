/*DomoticHome by THX
fore more inffo go to http://domotichome.heroku.com/masters
*/


#include <SPI.h>
#include <Ethernet.h>
//#include <mcp9700a.h>


byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x86, 0x3F };
byte ip[] = { 192 ,168 ,178 ,101 };
byte gateway[] = { 192 ,168 ,178 ,1 };
byte subnet[] = { 255 ,255 ,255 ,0 };
EthernetServer server(8496); 

String readString = String(30);


void setup()
{
	Ethernet.begin(mac, ip, gateway, subnet);
	delay(1000);
	pinMode(48, OUTPUT);
	digitalWrite(48, LOW);
	pinMode(49, OUTPUT);
	digitalWrite(49, LOW);
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
	EthernetClient client = server.available();
	if (client)
	{
		while (client.connected())
		{
			if (client.available())
			{
				char c = client.read();
				if (readString.length() < 30)
				{
					readString = readString + c;
				}
				if (c == '\n')
				{
					Serial.print(readString);
					client.println("HTTP/1.1 200 OK");
					client.println("Content-Type: text/html");
					client.println();

					if(readString.startsWith("GET /?out=48&status=1"))
					{
						Serial.print("\n 48 HIGH \n");
						digitalWrite(48, HIGH);
						digitalWrite(49,LOW);
						digitalWrite(47,LOW);
						digitalWrite(46,LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(48);
						client.print("\"}");
					}

					if(readString.startsWith("GET /?out=48&status=0"))
					{
						Serial.print("\n 48 LOW \n");
						digitalWrite(48, LOW);
						client.print("{\"status\" : \"0\" , \"out\" : \"");
						client.print(48);
						client.print("\"}");
					}

					if(readString.startsWith("GET /?out=49&status=1"))
					{
						Serial.print("\n 49 HIGH \n");
						digitalWrite(49, HIGH);
						digitalWrite(48,LOW);
						digitalWrite(47,LOW);
						digitalWrite(46,LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(49);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=49&status=0"))
					{
						Serial.print("\n 49 LOW \n");
						digitalWrite(49, LOW);
						client.print("{\"status\" : \"0\" , \"out\" : \"");
						client.print(49);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=47&status=1"))
					{
						Serial.print("\n 47 HIGH \n");
						digitalWrite(47, HIGH);
						digitalWrite(49,LOW);
						digitalWrite(48,LOW);
						digitalWrite(46,LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(47);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=47&status=0"))
					{
						Serial.print("\n 47 LOW \n");
						digitalWrite(47, LOW);
						client.print("{\"status\" : \"0\" , \"out\" : \"");
						client.print(47);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=46&status=1"))
					{
						Serial.print("\n 46 HIGH \n");
						digitalWrite(46, HIGH);
						digitalWrite(49,LOW);
						digitalWrite(48,LOW);
						digitalWrite(47,LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(46);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=46&status=0"))
					{
						Serial.print("\n 46 LOW \n");
						digitalWrite(46, LOW);
						client.print("{\"status\" : \"0\" , \"out\" : \"");
						client.print(46);
						client.print("\"}");
					}

					if(readString.startsWith("GET /?out=45&status=1"))
					{
						Serial.print("\n 45 HIGH LOW \n");
						digitalWrite(45, HIGH);
						delay(100);
						digitalWrite(45, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(45);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=44&status=1"))
					{
						Serial.print("\n 44 HIGH LOW \n");
						digitalWrite(44, HIGH);
						delay(100);
						digitalWrite(44, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(44);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=43&status=1"))
					{
						Serial.print("\n 43 HIGH LOW \n");
						digitalWrite(43, HIGH);
						delay(100);
						digitalWrite(43, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(43);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=42&status=1"))
					{
						Serial.print("\n 42 HIGH LOW \n");
						digitalWrite(42, HIGH);
						delay(100);
						digitalWrite(42, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(42);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=41&status=1"))
					{
						Serial.print("\n 41 HIGH LOW \n");
						digitalWrite(41, HIGH);
						delay(100);
						digitalWrite(41, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(41);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=40&status=1"))
					{
						Serial.print("\n 40 HIGH LOW \n");
						digitalWrite(40, HIGH);
						delay(100);
						digitalWrite(40, LOW);
						client.print("{\"status\" : \"1\" , \"out\" : \"");
						client.print(40);
						client.print("\"}");
					}
					
					if(readString.startsWith("GET /?out=all"))
					{
						Serial.print("\n OUT ALL\n");
						client.print("{\"ip\" : \"192.168.178.101\", ");
						client.print("\"devices\" : ");
						client.print("[{ \"type\" : \"light\", \"name\" : \"C\", \"out\" : \"");
						client.print("48");
						client.print("\"}");
						client.print(",{ \"type\" : \"light\", \"name\" : \"D\", \"out\" : \"");
						client.print("49");
						client.print("\"}");
						client.print(",{ \"type\" : \"light\", \"name\" : \"B\", \"out\" : \"");
						client.print("47");
						client.print("\"}");
						client.print(",{ \"type\" : \"light\", \"name\" : \"A\", \"out\" : \"");
						client.print("46");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"3_OFF\", \"out\" : \"");
						client.print("45");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"3_ON\", \"out\" : \"");
						client.print("44");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"2_OFF\", \"out\" : \"");
						client.print("43");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"2_ON\", \"out\" : \"");
						client.print("42");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"1_OFF\", \"out\" : \"");
						client.print("41");
						client.print("\"}");
						client.print(",{ \"type\" : \"gate\", \"name\" : \"1_ON\", \"out\" : \"");
						client.print("40");
						client.print("\"}");
						client.print("]}");
					}

					readString="";
					client.stop();
				}
			}
		}
	}
}