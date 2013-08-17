// Franzis Arduino
// Sound

int Speaker=8;

void setup() 
{ 
   pinMode(Speaker, OUTPUT);
} 

void loop() 
{ 
   tone(Speaker,550,450);
   delay(3000);
}

