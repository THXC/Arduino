// Franzis Arduino
// Softer Blinker

int x;
int PWMpin = 9;


void setup()
{
  // Dieses Mal benötigen wir hier nichts!
}


void loop()
{

   int x = 1;
   for (int i = 0; i > -1; i = i + x)
   {
      analogWrite(PWMpin, i);
      if (i = 255) x = -1;            
      delay(10);
   } 

}

