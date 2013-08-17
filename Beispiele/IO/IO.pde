// Franzis Arduino
// Taster über IO-Pin einlesen

int led=13;   
int pin=12;   
int value=0;  
  
void setup()  
{  
  pinMode(led,OUTPUT);    
  pinMode(pin,INPUT);
  digitalWrite(pin, HIGH);  
}  
  
void loop()  
{  
  value=digitalRead(pin);    
  digitalWrite(led,value);  
}                            


