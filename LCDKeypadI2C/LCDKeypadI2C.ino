#include <LiquidCrystal_I2C.h>									//| \*/
#include <Wire.h>												//|-----Lib incuded 
#include <i2ckeypad.h>											//| /*\

#define ROWS 4													// keypads buttons
#define COLS 3													// 4*3

#define PCF8574_ADDR 0x39										// address of I2C

LiquidCrystal_I2C lcd(0x38,20,4);								// address of LCD included display size
i2ckeypad kpd = i2ckeypad(PCF8574_ADDR, ROWS, COLS);			// redefined

void setup()													// setup
{
	Wire.begin();												//transmision begin
	kpd.init();													//init of keypad
	lcd.init();													//init of LCD
	lcd.backlight();											//the backlight its on
	lcd.setCursor(0,0);											//when begin to dispaly data
	lcd.print("Testing Keypad");								//print msg on LCD
}

void loop()														//loop
{
	char key = kpd.get_key();									//redefined keypad to key
	if(key != '\0')												//get key
	{
		lcd.clear();											//LCD Clear
		lcd.setCursor(0,0);										//LCD wher begin to display data
		lcd.print(key);											//LCD print/display data
	}
}