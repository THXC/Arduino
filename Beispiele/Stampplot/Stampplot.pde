// Franzis Arduino
// Stampplot Datenschreiber

int LED=13;
int adc0=0;

void setup()
{
  Serial.begin(19200);
  pinMode(LED,OUTPUT);  
  
  delay(10000);
  
  // Stampplot Einstellungen senden
  Serial.println("!RSET");                   // Reset plot To clear data
  Serial.println("!TITL Arduino DEMO-PLOT"); // Caption form
  Serial.println("!PNTS 300");               // 1000 sample data points
  Serial.println("!TMAX 60");                // Max 60 seconds
  Serial.println("!SPAN 0,1023");            // 0-1023 Span
  Serial.println("!AMUL 1");                 // Multiply data by 1
  Serial.println("!DELD");                   // Delete Data File
  Serial.println("!SAVD ON");                // Save Data
  Serial.println("!TSMP ON");                // Time Stamp On
  Serial.println("!CLMM");                   // Clear Min/Max
  Serial.println("!CLRM");                   // Clear Messages
  Serial.println("!PLOT ON");                // Start Plotting
  Serial.println("!RSET");                   // Reset plot To time 0  
}


void loop()
{
   adc0=analogRead(0);
   Serial.print(adc0);
   Serial.write(13);

   if(adc0>700)
   {
      Serial.println("!USRS ADC RAW > 800!");
      Serial.println("ADC RAW ist größer 800");
      digitalWrite(LED,HIGH);
   }

   if(adc0<150)
   {
      Serial.println("!USRS ADC RAW < 250!");
      Serial.println("ADC RAW ist kleiner 150");
      digitalWrite(LED,LOW);
   }

   delay(200);
  
}


