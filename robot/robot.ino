#include <PS3BT.h>
#include <HBridge.h>
#include <usbhub.h>

USB Usb;
USBHub Hubl(&Usb);
BTD Btd(&Usb);
PS3BT PS3(&Btd,0x00, 0x09, 0xDD, 0x50, 0x8F,0xC6);

HBridge hb1(1);				//
HBridge hb2(2);				//
HBridge hb3(3);				//
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

	hb1.setEnablePins(2,3);
	hb2.setEnablePins(50,29);
	hb3.setEnablePins(31,41);
	hb4.setEnablePins(53,43);

	hb1.setControlPins(42,44,46,48);
	hb2.setControlPins(52,23,25,27);
	hb3.setControlPins(33,35,37,39);
	hb4.setControlPins(45,47,49,51);
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

/*Led Blink if connected to controller*/
void LedBlink()
{
	digitalWrite(22, HIGH);
	delay(350);
	digitalWrite(22, LOW);
	delay(350);
}