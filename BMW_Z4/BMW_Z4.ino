#include <PS3BT.h>
#include <HBridge.h>
#include <usbhub.h>

USB Usb;
USBHub Hubl(&Usb);
BTD Btd(&Usb);
PS3BT PS3(&Btd,0x00, 0x09, 0xDD, 0x50, 0x8F,0xC6);

int x = 200;

HBridge hb1;				//

void setup()
{
	Serial.begin(115200);
	Usb.Init();
	if (Usb.Init() == -1)
	{
		Serial.print(F("\r\nOSC did not start"));
		while(1); //halt
	}
	Serial.print(F("\r\nPS3 Bluetooth Library Started"));

	hb1.setEnablePins(3,9);
	hb1.setControlPins(40,41,42,43);
}

void loop()
{
	/*THE MANIN PROGRAM*/
	Usb.Task();
	if(PS3.PS3Connected)
	{
		//LedBlink();
		MotorOnePWM();
	}
}

/*Motor PWM*/
void MotorOnePWM()
{
	//Go Forward With L2
	if ((PS3.getAnalogButton(L2))&&!(PS3.getAnalogButton(R2)))
	{
		hb1.PWMA(PS3.getAnalogButton(L2));
		hb1.movePWMAForward();
	}

	//Go Backward With R2
	if ((PS3.getAnalogButton(R2))&&!(PS3.getAnalogButton(L2)))
	{
		hb1.PWMA(PS3.getAnalogButton(R2));
		hb1.movePWMABackward();
	}

	//Motor Stop
	if ((PS3.getAnalogButton(L2))&&(PS3.getAnalogButton(R2)))
	{
		hb1.motorAStall();
	}	
	
	//hb1.motorAOFF();
		
	//Left
	if(PS3.getAnalogHat(RightHatX)<90)
	{
		hb1.PWMB(x);
		hb1.turnBRight();		
	}
	
	//Right
	if(PS3.getAnalogHat(RightHatX)>160)
	{
		hb1.PWMB(x);
		hb1.turnBLeft();
	}
	
	//OFF /Reset
	hb1.motorOFF();

}

/*Led Blink if connected to controller*/
void LedBlink()
{
	digitalWrite(22, HIGH);
	delay(350);
	digitalWrite(22, LOW);
	delay(350);
}