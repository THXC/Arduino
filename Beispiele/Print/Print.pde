// Franzis Arduino
// Arduino Serial.print Funktion

int x;


void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Serial.print Funktion"); 
   Serial.println(); 
}


void loop()
{    

  Serial.print("NO FORMAT");      
  Serial.print("\t");              // Print Tab

  Serial.print("DEC");             // Decimal  
  Serial.print("\t");      

  Serial.print("HEX");             // Hexadezimal
  Serial.print("\t");   

  Serial.print("OCT");             // Octal
  Serial.print("\t");

  Serial.print("BIN");             // Binär
  Serial.print("\t"); 

  Serial.println("BYTE");         // Byte

  // only part of the ASCII chart, change to suit
  for(x=0; x< 64; x++)
  {    

    // Ausgabe in verschiedenen Formaten
    Serial.print(x);       
    Serial.print("\t");   

    Serial.print(x, DEC);  
    Serial.print("\t");    

    Serial.print(x, HEX);  
    Serial.print("\t");   

    Serial.print(x, OCT);  
    Serial.print("\t");    

    Serial.print(x, BIN); 
    Serial.print("\t");    

    Serial.println(x, BYTE);     
    delay(200);            // 200ms Pause
  }
  
  Serial.println("");    

}



