// Franzis Arduino
// Poti einlesen

int Poti=0;
int raw,raw_last,raw_min,raw_max=0;
int hysterese=10;


void setup()
{
  Serial.begin(9600);
  Serial.println("Potenziometer professionell auslesen");
  Serial.println();
}


void loop()
{
  
  raw=analogRead(Poti);
  raw_min=raw_last-hysterese;
  raw_max=raw_last+hysterese;
  
  if((raw!=raw_last))
  {
    if((raw>raw_max)||(raw<raw_min))
    {
      Serial.println(raw);
      raw_last=raw;
    }
  }
   
}

