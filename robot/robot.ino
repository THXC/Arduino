#include <PS3BT.h>
#include <HBridge.h>
#include <usbhub.h>

USB Usb;
USBHub Hubl(&Usb);
BTD Btd(&Usb);
PS3BT PS3(&Btd,0x00, 0x09, 0xDD, 0x50, 0x8F,0xC6);

HBridge hb1(1);				//napend gassienicowy
HBridge hb2(2);				//obracanie reki prawo/lewo podniesc opusc
HBridge hb3(3);				//podniesc opusc
HBridge hb4(4);				//

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

	hb1.setEnablePins(9,3);
	hb2.setEnablePins(40,41);
	hb3.setEnablePins(46,47);
	hb4.setEnablePins(52,53);

	hb1.setControlPins(34,35,32,33);
	hb2.setControlPins(38,39,36,37);
	hb3.setControlPins(44,45,42,43);
	hb4.setControlPins(50,51,48,49);
}

void loop()
{
	Usb.Task();
	if(PS3.PS3Connected)
	{
		MotorOnePWM();
	}
}

/*Motor PWM*/
void MotorOnePWM()
{
	//Go Backward With L2
	if ((PS3.getAnalogButton(L2))&&!(PS3.getAnalogButton(R2))&&!(PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(L2));
		hb1.movePWMBackward();
	}

	//Go Forward With R2
	if ((PS3.getAnalogButton(R2))&&!(PS3.getAnalogButton(L2))&&!(PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(R2));
		hb1.movePWMForward();
	}

	//Rotate Conterclockwise L2+X
	if ((PS3.getAnalogButton(L2))&&!(PS3.getAnalogButton(R2))&&(PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(L2));
		hb1.PWMturnLeft();
	}

	//Rotate Clockwise R2+X
	if ((PS3.getAnalogButton(R2))&&!(PS3.getAnalogButton(L2))&&(PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(R2));
		hb1.PWMturnRight();
	}

	//Motor OFF
	hb1.Stop();
}
