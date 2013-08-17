// Franzis Arduino
// Ports über DOT.NET steuern

int LED=13;
int IO_5=5;
int input=0;


void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);  
  pinMode(IO_5,OUTPUT);
}


void loop()
{

  input=Serial.read();
  
  switch(input)
  {
    case 10:
    digitalWrite(LED,HIGH);
    break;
    
    case 20:
    digitalWrite(LED,LOW);
    break;
   
    case 30:
    digitalWrite(IO_5,HIGH);
    break;
    
    case 40:
    digitalWrite(IO_5,LOW);
    break;
    
    case 100:
    digitalWrite(LED,LOW);
    digitalWrite(IO_5,LOW);
    break;
    
  }   


}


