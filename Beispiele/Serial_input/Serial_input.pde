// Franzis Arduino
// Arduino Serial Input Funktion

int LEDpin = 13;


void setup()
{
   pinMode(LEDpin,OUTPUT);
   Serial.begin(9600); 
   Serial.println("Arduino Serial Input"); 
   Serial.println(); 
   //Serial.println("Geben Sie einen Text mit max. 80 Zeichen ein: ");    
}


void loop()
{    
   byte input;
   byte in[80];
   byte x;
   char Command_1[] ={"LED EIN"};
   

   

    if(Serial.available() > 0)
    {
      
      do
      {
        input=Serial.read();
        in[x]=input;
        x++;
      }while(input==10 || input ==0 || input ==13 || x > 20); 
        
      in[x]=10;
      in[x+1]=13;
      
      
      Serial.write(in);
      
      if(in==Command_1)
      {
        Serial.println("LED = EIN");
      }
      
     
    }
  
}





