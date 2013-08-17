// Franzis Arduino
// Analog Write 

int value;
int LEDgruen=10;
int LEDrot=11;


void setup() 
{
  // Dieses mal kommt hier nichts hin
}

void loop()
{

 for(value=0;value<255;value++)
 { 
   analogWrite(LEDgruen, value);
   analogWrite(LEDrot, 255-value); 
   delay(5);
 }
 
 delay(1000);

 for(value=255;value!=0;value--)
 { 
   analogWrite(LEDgruen, value);
   analogWrite(LEDrot, 255-value); 
   delay(5);
 }
 
 delay(1000); 
 
}
