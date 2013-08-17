// Franzis Arduino
// ADC 

int ADC0=0;   
int value;
int LEDpin=13;


void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  value=analogRead(ADC0);
  Serial.print("ADC0 = ");  
  Serial.println(value);
  delay(1000);  
}
