// Franzis Arduino
// Arduino Continue

int i=0;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Continue"); 
   Serial.println(); 
}


void loop()
{
 
  for(i=0;i<10;i++)
  {
    if(i%2==0)
    {
      continue;
    }
    Serial.print(i);
    Serial.print(" nicht durch 2 teilbar!"); 
    Serial.println();
  }
  
   while(1);
}


