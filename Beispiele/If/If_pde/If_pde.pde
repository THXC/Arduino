// Franzis Arduino
// if... 

int x;

void setup()
{
 Serial.begin(9600); 
 Serial.println("If Anweisungen"); 
 Serial.println(); 
}



void loop()
{
   
  if(x==10)
  {
    Serial.println("Die Variable X hat nun den Zaehlerstand 10!");
    while(1);
  }

  x++;
  
}

