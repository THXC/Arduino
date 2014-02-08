//*************************************************************************************************************************************
// Declarations
//*************************************************************************************************************************************
#include <SPI.h>
#include <Ethernet.h>

//*************************************************************************************************************************************
// Wired configuration parameters
//*************************************************************************************************************************************
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x86, 0x3F};
byte ip[] = {192, 168, 178, 199};
byte gateway[] = {192, 168, 178, 1};
byte subnet[] = {255, 255, 255, 0};
EthernetServer server(8496);

//char buffer[20];
String buffer = "";

void setup()
{
  pinMode(8,OUTPUT);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
}

void loop()
{
  EthernetClient client = server.available();
  if (client) 
  {
    boolean currentLineIsBlank = true;  
    while (client.connected()) 
    {
      if (client.available()) 
      {
        char c = client.read();
        Serial.print(c);   
        buffer+=c;
        
        int val;
        if (c == 'O')
        {
          digitalWrite(8,HIGH);
        }
        else if (c == 'F')
        {
          digitalWrite(8,LOW);
        }
      }
    }
  }
}
