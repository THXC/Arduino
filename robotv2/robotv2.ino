#include <PS3BT.h>
#include <HBridge.h>
#include <usbhub.h>

USB Usb;
USBHub Hubl(&Usb);
BTD Btd(&Usb);
PS3BT PS3(&Btd,0x00, 0x09, 0xDD, 0x50, 0x8F,0xC6);


/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//initialization
HBridge hb1(1);				//
HBridge hb2(2);				//
HBridge hb3(3);				//
HBridge hb4(4);				//

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//Setup
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
	hb2.setEnablePins(50,29);
	hb3.setEnablePins(31,41);
	hb4.setEnablePins(53,43);

	hb1.setControlPins(42,44,46,48);
	hb2.setControlPins(52,23,25,27);
	hb3.setControlPins(33,35,37,39);
	hb4.setControlPins(45,47,49,51);
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//loop
void loop()
{
	/*THE MANIN PROGRAM*/
	Usb.Task();
	if(PS3.PS3Connected)
	{
		//LedBlink();
		//MotorOnePWM();
		//MotorTwoA();
		MotorTwoB();
		MotorThreeA();
		//MotorThreeB();
		//MotorFourA();
	}
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*																																							*/
/*																																							*/
/*																																							*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//PWM #1L298N controlling the movement
void MotorOnePWM()
{
	//Go Backward With L2
	if ((PS3.getAnalogButton(L2)) &&! (PS3.getAnalogButton(R2)) &&! (PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(L2));
		hb1.movePWMBackward();
	}

	//Go Forward With R2
	if ((PS3.getAnalogButton(R2)) &&! (PS3.getAnalogButton(L2)) &&! (PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(R2));
		hb1.movePWMForward();
	}

	//Rotate Counterclockwise L2+X
	if ((PS3.getAnalogButton(L2)) &&! (PS3.getAnalogButton(R2)) && (PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(L2));
		hb1.PWMturnLeft();
	}

	//Rotate Clockwise R2+X
	if ((PS3.getAnalogButton(R2)) &&! (PS3.getAnalogButton(L2)) && (PS3.getButtonPress(CROSS)))
	{
		hb1.PWM(PS3.getAnalogButton(R2));
		hb1.PWMturnRight();
	}

	//Motor OFF
	hb1.motorStop();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//#2 L298N for rotting first motor
void MotorTwoA()
{
	//turn left
	if((PS3.getButtonPress(L1)) &&! (PS3.getButtonPress(R1)))
	{
		hb2.motorAON();
		hb2.turnALeft();
	}
	
	//turn right
	if ((PS3.getButtonPress(R1)) &&! (PS3.getButtonPress(L1)))
	{
		hb2.motorAON();
		hb2.turnARight();
	}
	//Motor 2A OFF
	hb2.motorAOFF();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//#2 L298N controlling up down motion part. I
void MotorTwoB()
{
	//move down arm part. I
	if(PS3.getAnalogHat(LeftHatY)<100)
	{
		hb2.motorBON();
		hb2.moveBDown();
	}
	
	//move up arm part. I
	if(PS3.getAnalogHat(LeftHatY)>156)
	{
		hb2.motorBON();
		hb2.moveBUP();
	}
	
	//motor 2B OFF
	hb2.motorBOFF();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//#3 L298N controlling grasper
void MotorThreeA()
{
	//drop
	if (PS3.getButtonPress(L3))
	{
		hb3.motorAON();
		hb3.ADrop();
	}
	
	//catch
	if (PS3.getButtonPress(R3))
	{
		hb3.motorAON();
		hb3.ACatch();
	}
	
	//motor 3A OFF
	hb3.motorAOFF();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//#3 L298N controlling up down motion part. II
void MotorThreeB()
{
	//move down arm part. II
	if(PS3.getAnalogHat(RightHatY)<100)
	{
		hb3.motorBON();
		hb3.moveBDown();
	}
	
	//move up arm part. II
	if(PS3.getAnalogHat(RightHatY)>156)
	{
		hb3.motorBON();
		hb3.moveBUP();
	}
	
	//motor 3B OFF
	hb3.motorBOFF();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
//#4 L298N controlling the last up down joint
void MotorFourA()
{
	//joint down
	if(PS3.getButtonPress(DOWN))
	{
		hb4.motorAON();
		hb4.moveADown();
	}
	
	//joint up
	if(PS3.getButtonPress(UP))
	{
		hb4.motorAON();
		hb4.moveAUP();
	}
	
	//motor 4A OFF
	hb4.motorAOFF();
}

/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*..........................................................................................................................................................*/
/*Led Blink if connected to controller*/
/*void LedBlink()
{
	digitalWrite(22, HIGH);
	delay(350);
	digitalWrite(22, LOW);
	delay(350);
}
*/