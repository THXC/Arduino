// Franzis Arduino
// Zeitmessung 1

unsigned long value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Zeit: ");
  value=micros();
  Serial.println(value);
  delay(1000);
}






