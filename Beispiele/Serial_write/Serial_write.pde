// Franzis Arduino
// Arduino Serial.write Funktion

byte val = 65;
char str[] = "Test";
byte buf[] = {'H','a','l','l','o'};
byte len = 3;



void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Serial.write Funktion"); 
   Serial.println(); 
}


void loop()
{    

  Serial.println("ASCII Zeichen");
  Serial.write(val);
  Serial.println();
  
  Serial.println("String 1");
  Serial.write(str);
  Serial.println();
  
  Serial.println("String 2");
  Serial.write(buf, len);
  Serial.println();

  while(1);          
  
}



