// Franzis Arduino
// Do While

int X=0; 

void setup()
{ 
 Serial.begin(9600); 
 Serial.println("Do und Do While Programm"); 
 Serial.println(); 
} 

void loop()  
{ 

  while(1)
  {
    X++;
    Serial.print(X);
    Serial.println();
    if(X>9) break;
  }

  X=0;
  Serial.println();
   
  while(X<10)
  {
    X++;
    Serial.print(X);
    Serial.println();
  }

  X=0;
  Serial.println();  
  
  // Do While
  do
  {
    X++;
    Serial.print(X);
    Serial.println();    
  }while( X < 10 );

  
  while(1);
  
}
