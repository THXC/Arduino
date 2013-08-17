// Franzis Arduino
// LED Blinkfrequenz über ADC einstellen

int ADC0=0;   
int value;
int LEDpin=13;


void setup() 
{
  pinMode(LEDpin,OUTPUT);
}

void loop()
{
  value=analogRead(ADC0);    
  digitalWrite(LEDpin, HIGH);  
  delay(value);                
  digitalWrite(LEDpin, LOW);   
  delay(value);                  
}
