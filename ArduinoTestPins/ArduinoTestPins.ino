void setup()
{
  /* add setup code here */
 
}

void loop()
{

  /* add main program code here */
  for(int i=22; i<=53; i++)
  {
	  pinMode(i, OUTPUT);
	  digitalWrite(i, HIGH);
  }

}
