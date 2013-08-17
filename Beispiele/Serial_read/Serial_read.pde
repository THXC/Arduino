// Franzis Arduino
// Arduino Serial Read

#define INLENGTH 20
#define INTERMINATOR 13

char inString[INLENGTH+1];
int inCount;


void setup()
{
   Serial.begin(9600); 
   Serial.println("Arduino Serial read"); 
   Serial.println(); 
   Serial.println("Geben Sie einen Text mit max. 20 Zeichen ein: ");    
}


void loop()
{    

      inCount = 0;    
      
      do 
      {
        while (Serial.available()==0);       
        inString[inCount] = Serial.read();     
        if(inString[inCount]==INTERMINATOR) break;
      }while(++inCount < INLENGTH);
      
      inString[inCount] = 0;                  
      Serial.print(inString);   
     
}





