// Franzis Arduino
// if... else...

int x;

void setup()
{
 Serial.begin(9600); 
 Serial.println("If und Else Anweisungen"); 
 Serial.println(); 
}



void loop()
{
   
  if(x==10)
  {
    Serial.println("Die Variable X hat nun den Zaehlerstand 10!");
    while(1);
  }
  else
  {
    Serial.print("X = ");
    Serial.print(x);
    Serial.println();
  }

  x++;
  
}

