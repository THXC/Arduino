// Franzis Arduino
// Ansteuern eines 4bit LCDs

/*

 ---[ Anschluss ]---------------------
 
 >>> LCD <<<          >>> Arduino <<<
 
 * RW pin           = GND
 * LCD RS pin       = digital pin 12
 * LCD Enable pin   = digital pin 11
 * LCD D4 pin       = digital pin 5
 * LCD D5 pin       = digital pin 4
 * LCD D6 pin       = digital pin 3
 * LCD D7 pin       = digital pin 2
 * Vee              = Poti Schleifer
 
*/


#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Poti = 0;
int raw=0;
int x=0;
int i=0;


void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);          // LCD mit 4 Zeilen und je 20 Zeichen
  lcd.setCursor(0, 0);       // Zeile 1 erstes Zeichen
  lcd.print("Arduino ist Spitze!");  
  
  lcd.noDisplay();           // LCD ausschalten
  delay(1500);      
  lcd.display();             // LCD wieder einschalten
}


void loop()
{
   
  lcd.setCursor(0, 1);  
  lcd.print(millis()/1000);  // vergangene Zeit in Sekunden ausgeben 
  lcd.print(" Sekunden");
  
  if(x!=(millis()/500))
  {
    raw=analogRead(Poti);
    lcd.setCursor(0,2);
    lcd.print("ADC0 = ");
    lcd.setCursor(7,2);
    lcd.print("    ");
    lcd.setCursor(7,2);  
    lcd.print(raw);
    x=millis()/500;
  }

 
  
  if(Serial.available()>0)
  {
     if(i==20)
     {
       i=0;
       lcd.setCursor(0,3);
       lcd.print("                    ");
     }   
     
     lcd.setCursor(i,3);
     lcd.write(Serial.read());
     i++; 
  }

}


