// Franzis Arduino
// Auslesen einer GPS Maus 4800Baud

 #include <string.h>
 #include <ctype.h>

 int ledPin = 13;                  // LED
 int rxPin = 0;                    // RX PIN 
 int txPin = 1;                    // TX TX
 int byteGPS=-1;
 char linea[300] = "";
 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int bien=0;
 int conta=0;
 int indices[13];

 void setup()
{
   pinMode(ledPin, OUTPUT);       
   pinMode(rxPin, INPUT);
   pinMode(txPin, OUTPUT);
   Serial.begin(4800);
   for (int i=0;i<300;i++){      
     linea[i]=' ';
   }   
 }

 void loop()
{
   digitalWrite(ledPin, HIGH);
   byteGPS=Serial.read();      
   if (byteGPS == -1)
   {         
     delay(100); 
   } 
   else
   {
     linea[conta]=byteGPS;       
     conta++;                      
     Serial.print(byteGPS, BYTE); 
     if (byteGPS==13)
     {            
       digitalWrite(ledPin, LOW); 
       cont=0;
       bien=0;
       for (int i=1;i<7;i++)
       {    
         if (linea[i]==comandoGPR[i-1])
         {
           bien++;
         }
       }
       if(bien==6)
       {         
         for (int i=0;i<300;i++){
           if (linea[i]==',')
           { 
             indices[cont]=i;
             cont++;
           }
           if (linea[i]=='*')
           {  
             indices[12]=i;
             cont++;
           }
         }
         
         Serial.println("");     
         Serial.println("");
         Serial.println("---------------");
         for (int i=0;i<12;i++){
           switch(i){
             case 0 :Serial.print("Time in UTC (HhMmSs): ");break;
             case 1 :Serial.print("Status (A=OK,V=KO): ");break;
             case 2 :Serial.print("Latitude: ");break;
             case 3 :Serial.print("Direction (N/S): ");break;
             case 4 :Serial.print("Longitude: ");break;
             case 5 :Serial.print("Direction (E/W): ");break;
             case 6 :Serial.print("Velocity in knots: ");break;
             case 7 :Serial.print("Heading in degrees: ");break;
             case 8 :Serial.print("Date UTC (DdMmAa): ");break;
             case 9 :Serial.print("Magnetic degrees: ");break;
             case 10 :Serial.print("(E/W): ");break;
             case 11 :Serial.print("Mode: ");break;
             case 12 :Serial.print("Checksum: ");break;
           }
           for (int j=indices[i];j<(indices[i+1]-1);j++)
           {
             Serial.print(linea[j+1]); 
           }
           Serial.println("");
         }
         Serial.println("---------------");
       }
       conta=0;                    
       for (int i=0;i<300;i++)
       {   
         linea[i]=' ';             
       }                 
     }
   }
 }



