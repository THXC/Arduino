
void setup()
{
	Serial.begin(115200);
	Serial.print("RDY");
	Serial1.begin(115200);
}

void loop()
{
	myRead();
}

byte myRead ()
{
  while (Serial.available () < 1)
  {}
  return Serial.read () ;
}

int readSample ()
{
  byte high, low ;
  do
  {
    do
    {
      high = myRead () ;
    } while ((high & 0xE0) != 0xE0) ;  // wait for high byte tag
    low = myRead () ;
  } while ((low & 0xE0) != 0x00) ;  // if low byte isn't tagged correctly retry the whole thing
  return ((high & 0x1F) << 5) | low ;  // stictch together
}
