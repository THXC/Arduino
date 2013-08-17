// Franzis Arduino
// Zufallszahlen

int x,y=0;


void setup()
{
  randomSeed(100);
  Serial.begin(9600);
  Serial.println("Arduino Zufallszahlen");
  Serial.println();  
}


void loop()
{

 
  for(x=0;x<20;x++)
  {
    y=random(0, 10); 
    Serial.print(y);
    Serial.print(",");
  }
  Serial.println(); 
 
  
  for(x=0;x<20;x++)
  {
    y=random(10,100); 
    Serial.print(y);
    Serial.print(",");
  }
  Serial.println(); 
 
  
  for(x=0;x<20;x++)
  {
    y=random(0,x+1); 
    Serial.print(y);
    Serial.print(",");
  } 
  Serial.println(); 
  
  while(1);
  
}



