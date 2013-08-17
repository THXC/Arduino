// Franzis Arduino
// Switch Case

int x;

void setup()
{
 Serial.begin(9600); 
 Serial.println("Switch Case Anweisungen"); 
 Serial.println(); 
}


void loop()
{
   
  switch(x)
  {
     case 10:
     Serial.println("Wir haben 10 erreicht");   
     break;
     
     case 20:
     Serial.println("Wir haben 20 erreicht");   
     break;
     
     case 30:
     Serial.println("Wir haben 30 erreicht");   
     while(1);
     break;
     
    default:
     Serial.print("X = ");
     Serial.print(x);
     Serial.println();    
  }
   
  x++;
  
}

