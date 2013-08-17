// Franzis Arduino
// Sirene

int Speaker=9;
int i=0;

void setup() 
{ 
  pinMode(Speaker, OUTPUT);
} 

void loop() 
{ 
  for(i=120;i<160;i++)
  {
    tone(Speaker,500,i);
    delay(1);
  }
}

