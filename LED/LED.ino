 //Define our variables
 //int LEDPin[]={2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //original
 //int LEDPin[]={4, 7, 10, 13, 3, 6, 9, 12, 2, 5, 8, 11};
 //int LEDPin[]={4, 7, 10, 13, 12, 11, 8, 5, 2, 3, 6, 9};
 //int LEDPin[]={2, 3, 4, 7, 6, 5, 8, 9, 10, 13, 12, 11};
 //int LEDPin[]={9, 6, 5, 8, 11, 12, 13, 10, 7, 4, 3, 2};
 int LEDPin[]={2, 3, 4, 7, 10, 13, 12, 11, 8, 5, 6, 9};
  
 int LEDCount=12;    //number of LEDs

void setup() {
   for (int Pin=0; Pin < LEDCount; Pin++)  {  //initialize each LED 
     pinMode(LEDPin[Pin], OUTPUT);          
     digitalWrite(LEDPin[Pin], HIGH);         //Turn the LED on
     delay(50);
     digitalWrite(LEDPin[Pin], LOW);          //Turn the LED back off
   }  
}

void loop() {
   for (int Pin=0; Pin < LEDCount; Pin++)  {  
     digitalWrite(LEDPin[Pin], HIGH);         //Turn the LED on
     delay(70);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {  
     delay(100);
     digitalWrite(LEDPin[Pin], LOW);          //Turn the LED back off
   }  
}