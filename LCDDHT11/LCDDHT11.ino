#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;
#define DHT11_PIN A0
LiquidCrystal_I2C lcd(0x38,20,4);  // set the LCD address to 0x38 for a 20 chars and 4 line display

void setup()
{
	lcd.init();	
  // Print a message to the LCD.
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Pomiar Temperatury ");
  lcd.setCursor(0,1);
  lcd.println("I Wilgotnosci ");
}

void loop()
{
   // READ DATA
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
		lcd.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		lcd.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		lcd.print("Time out error,\t"); 
		break;
    default: 
		lcd.print("Unknown error,\t"); 
		break;
  }
 // DISPLAT DATA
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity ");
  lcd.setCursor(0,1);
  lcd.print(DHT.humidity,1);
  lcd.print(" %");
  lcd.setCursor(0,2);
  lcd.print("Temperature ");
  lcd.setCursor(0,3);
  lcd.print(DHT.temperature,1);
  lcd.print(" C");

  delay(500);
  
}