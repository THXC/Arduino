// Franzis Arduino
// Arrays

int Array_1[3];
int Array_2[] = {1,2,3};

void setup()
{
 Serial.begin(9600); 
 Serial.println("Arduino Arrays"); 
 Serial.println(); 
}


void loop()
{
  byte x;
  
  Array_1[0] = 1;
  Array_1[1] = 2;
  Array_1[2] = 3;
  Array_1[3] = 4;
  
  Serial.println("Ausgabe Array 1 ");
  Serial.println("----------------");
  
  // Die Daten des ersten Arrays werden ausgeben
  for(x=0;x<3;x++)
  {
    Serial.print(Array_1[x]);
    Serial.println();
  }
  
  
  Serial.println("Ausgabe Array 2 ");
  Serial.println("----------------");
  
  // Die Daten des ersten Arrays werden ausgeben
  Serial.print(Array_2[0]);
  Serial.println();
  Serial.print(Array_2[1]);  
  Serial.println();
  Serial.print(Array_2[2]);
  
  while(1);
  
}


