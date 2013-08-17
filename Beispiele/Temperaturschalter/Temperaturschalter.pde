// Franzis Arduino
// Temperaturschalter

int LED=13;
int Uf=0;


void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);  
}


void loop()
{

  Uf=analogRead(0);
  Serial.print("Uf = ");
  Serial.println(Uf);
  
  if(Uf>40)digitalWrite(LED,HIGH);
  if(Uf<20)digitalWrite(LED,LOW);
  
  delay(250);

}


