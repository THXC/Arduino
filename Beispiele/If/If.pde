// Franzis Arduino
// if... elseif... else...

int x;

void setup()
{
 Serial.begin(9600); 
 Serial.println("If Anweisungen"); 
 Serial.println(); 
}



void loop()
{
  
  x++;
  
  if(x>10)
  {
    Serial.println("Die Variable X hat den Zählerstand 10!");
    while(1);
  }
  else
  {
    Serial.print("X = ");
    Serial.print(x);
    Serial.println();
  }

}

