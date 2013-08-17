int LEDPin[]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A0,A1,A2,A3,A4,A5 } ;
int LEDCount=20;

void setup() {
   for (int Pin=0; Pin < LEDCount; Pin++)  {  
     pinMode(LEDPin[Pin], OUTPUT);          
     digitalWrite(LEDPin[Pin], HIGH);         
     delay(200);
     digitalWrite(LEDPin[Pin], LOW);
   }
}
void loop() {
   for (int Pin=0; Pin < LEDCount; Pin++)  {  
     digitalWrite(LEDPin[Pin], HIGH);       
     delay(200);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], LOW);
     delay(100);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], HIGH);
     delay(100);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], LOW);
     delay(50);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], HIGH);
     delay(50);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], LOW);
     delay(100);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], HIGH);
     delay(100);
   }
   for (int Pin=0; Pin < LEDCount; Pin++)  {
     digitalWrite(LEDPin[Pin], LOW);
     delay(200);
   }
}
