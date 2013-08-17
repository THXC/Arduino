// Franzis Arduino
// Taster mit Pulldown

int led=13;   
int pin=12;   
int value=0;  
  
void setup()  
{  
  pinMode(led,OUTPUT);    
  pinMode(pin,INPUT);
}  
  
void loop()  
{  
  value=digitalRead(pin);    
  digitalWrite(led,value);  
}                            


