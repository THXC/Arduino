// Franzis Arduino
// DAC 

char buffer[18];
int pinPWM=9;
int raw=0;
float Volt=0;

void setup() 
{ 
  Serial.begin(9600);
  Serial.println("DAC mit PWM-Ausgang");
  Serial.println();
  Serial.println("Geben Sie einen Wert zwischen 0 und 255 ein");
  Serial.flush();
} 

void loop() 
{ 
  if (Serial.available() > 0)
  {
    int index=0;
    delay(100); // warten bis die Zeichen im Puffer sind
    int numChar = Serial.available();
    if (numChar>15)
    {
      numChar=15;
    }
    while (numChar--)
    {
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}

void splitString(char* data)
{
  Serial.print("Empfangen wurde der Wert: ");
  Serial.println(data);
  char* parameter; 
  parameter = strtok (data, " ,");
  while (parameter != NULL)
  {
    setPWM(parameter);
    parameter = strtok (NULL, " ,");
  }
  // Puffer wieder löschen
  for (int x=0; x<16; x++)
  {
    buffer[x]='\0';
  }
  Serial.flush();
}

void setPWM(char* data)
{
    int Ans = strtol(data, NULL, 10);
    Ans = constrain(Ans,0,255);
    analogWrite(pinPWM, Ans);
    Serial.print("PWM = ");
    Serial.println(Ans);
    delay(100);
    raw=analogRead(0);
    float ref=5.0/1024.0;
    Volt=raw*ref;
    Serial.print("Die Spannung am ADC0 betraegt: ");
    Serial.print(Volt);
    Serial.println(" Volt");
    Serial.println();
    Serial.println("Geben Sie einen Wert zwischen 0 und 255 ein");
}

