// Franzis Arduino
// Arduino Grad zu Fahrenheit

float Grad = 25.5;
float Fahrenheit = 88.2;

void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Grad zu Fahrenheit Umrechner"); 
   Serial.println(); 
}


void loop()
{    

 Serial.print(Grad);
 Serial.print(" Grad sind ");
 Serial.print(Grad_to_Fahrenheit(Grad));
 Serial.println(" Fahrenheit");
 Serial.println();
 
 Serial.print(Fahrenheit);
 Serial.print(" Fahrenheit sind ");
 Serial.print(Fahrenheit_to_Grad(Fahrenheit));
 Serial.println(" Grad");
 Serial.println();
 
 
 while(1);
   
}

float Grad_to_Fahrenheit(float grad)
{
  float erg; 
  erg = grad * 9 ; erg = erg / 5 ; erg = erg + 32;
  return erg; 
}


float Fahrenheit_to_Grad(float fahrenheit)
{
   float erg;
   erg = fahrenheit - 32 ; erg = erg * 5 ; erg = erg / 9;
   return erg;
}





