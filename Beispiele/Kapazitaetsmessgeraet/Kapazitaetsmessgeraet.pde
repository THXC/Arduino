// Franzis Arduino
// Autorange Kapazitätsmessgerät 1 nF ... 100µF

int messPort=12;
float c_time=0.0;
float kapazitaet=0.0;


void setup()
{
  Serial.begin(9600);
  Serial.println("Autorange Kapazitaetsmessgeraet 1 nF ... 100uF");
  Serial.println();
}


void loop()
{
  // Entladen
  pinMode(messPort,OUTPUT);
  digitalWrite(messPort,LOW);
  c_time=0.0;
  delay(1000);

  // Laden
  pinMode(messPort,INPUT);
  digitalWrite(messPort,HIGH);

  // Messen
  do
  {  
    c_time++;
  }while(!digitalRead(messPort));
  
  // Umrechnen
  kapazitaet=(c_time*0.042)*10.0;
  
  // Bereich
  if(kapazitaet<999)
  {
    Serial.print(kapazitaet);
    Serial.println("nF");
  }
  else
  {
    kapazitaet=kapazitaet/1000;
    Serial.print(kapazitaet);
    Serial.println("uF");
  }
 
  delay(1000);
  
}

