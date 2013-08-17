// Franzis Arduino
// Zeitmessung 1

unsigned long value;

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino Zeitmessung 1");
  Serial.println();
}


void loop()
{
  Serial.print("Zeit: ");
  value=millis();
  Serial.println(value);
  delay(1000);
}





