#include <PS3BT.h>
USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd,0x00, 0x09, 0xDD, 0x50, 0x8F,0xC6);

boolean printAngle;
boolean light;
boolean select;
boolean start;
boolean up;
boolean right;
boolean down;
boolean left;

//int valleft, valright;

/******************/
/**********#1 L298*/
/******************/
 #define One_Enable_A 9
 #define One_Input_1 34
 #define One_Input_2 35
 #define One_Enable_B 3
 #define One_Input_3 32
 #define One_Input_4 33

/******************/
/**********#2 L298*/
/******************/
 #define Two_Enable_A 40
 #define Two_Enable_B 41
 #define Two_Input_1 38
 #define Two_Input_2 39
 #define Two_Input_3 36
 #define Two_Input_4 37

/******************/
/**********#3 L298*/
/******************/
 #define Three_Enable_A 46
 #define Three_Enable_B 47
 #define Three_Input_1 44
 #define Three_Input_2 45
 #define Three_Input_3 42
 #define Three_Input_4 43

/******************/
/**********#4 L298*/
/******************/
 #define Four_Enable_A 52
 #define Four_Enable_B 53
 #define Four_Input_1 50
 #define Four_Input_2 51
 #define Four_Input_3 48
 #define Four_Input_4 49

void setup()
{
	/******************************************************/
	/* PS3BT **********************************************/
	/******************************************************/
	Serial.begin(115200);
	Usb.Init();
	if (Usb.Init() == -1)
	{
		Serial.print(F("\r\nOSC did not start"));
		while(1); //halt
	}
	/******************************************************/
	/*#1 L298**********************************************/
	/******************************************************/
	pinMode(One_Enable_A, OUTPUT);
	pinMode(One_Enable_B, OUTPUT);
	pinMode(One_Input_1, OUTPUT);
	pinMode(One_Input_2, OUTPUT);
	pinMode(One_Input_3, OUTPUT);
	pinMode(One_Input_4, OUTPUT);

	/******************************************************/
	/*#2 L298**********************************************/
	/******************************************************/
	pinMode(Two_Enable_A, OUTPUT);
	pinMode(Two_Enable_B, OUTPUT);
	pinMode(Two_Input_1, OUTPUT);
	pinMode(Two_Input_2, OUTPUT);
	pinMode(Two_Input_3, OUTPUT);
	pinMode(Two_Input_4, OUTPUT);

	/******************************************************/
	/*#3 L298**********************************************/
	/******************************************************/
	pinMode(Three_Enable_A, OUTPUT);
	pinMode(Three_Enable_B, OUTPUT);
	pinMode(Three_Input_1, OUTPUT);
	pinMode(Three_Input_2, OUTPUT);
	pinMode(Three_Input_3, OUTPUT);
	pinMode(Three_Input_4, OUTPUT);
	
	/******************************************************/
	/*#4 L298**********************************************/
	/******************************************************/
	pinMode(Four_Enable_A, OUTPUT);
	pinMode(Four_Enable_B, OUTPUT);
	pinMode(Four_Input_1, OUTPUT);
	pinMode(Four_Input_2, OUTPUT);
	pinMode(Four_Input_3, OUTPUT);
	pinMode(Four_Input_4, OUTPUT);
	
}

void loop()
{
	Usb.Task();
	if(PS3.PS3Connected)
	{	
		Start();
		Light();
		UPClick();
		RIGHTClick();
		DOWNClick();
		LEFTClick();
		
	}
}

/*************************************************************************************************************************************************/
/*OTHER STUF**************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*light*******************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*light on*/
void lightON()
{
	digitalWrite(22,HIGH);
}

/*light off with delay*/
void lightOFF()
{
	delay(1);
	digitalWrite(22,LOW);
}

/*light ON light OFF */
void Light()
{
	if(PS3.getButtonClick(SELECT))
	{
		light=!light;
	}
	if (select)
	{
		lightON();
		lightOFF();
	}
	else
	{
		Start();
		UPClick();
		RIGHTClick();
		DOWNClick();
		LEFTClick();
	}
}
/*************************************************************************************************************************************************/
/*robot move**************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*Start robot move*/
void Start()
{
	if(PS3.getButtonClick(START))
	{
		start=!start;
	}
	if(start)
	{
		MotorOnePWM();
	}
	else
	{
		Light();
		UPClick();
		RIGHTClick();
		DOWNClick();
		LEFTClick();
	}
}

/*Click Up*/
void UPClick()
{
	if(PS3.getButtonClick(UP))
	{
		up=!up;
	}
	if(up)
	{
		MotorTwoA();
		MotorTwoB();
	}
	else
	{
		Light();
		Start();
		RIGHTClick();
		DOWNClick();
		LEFTClick();
	}
}

/*Click Right*/
void RIGHTClick()
{
	if(PS3.getButtonClick(RIGHT))
	{
		right=!right;
	}
	if(right)
	{
		MotorThreeA();
	}
	else
	{
		Light();
		Start();
		UPClick();
		DOWNClick();
		LEFTClick();
	}
}

/*Click Down*/
void DOWNClick()
{
	if(PS3.getButtonClick(DOWN))
	{
		down=!down;
	}
	if(down)
	{
		//
	}
	/*else
	{
		Light();
		Start();
		UPClick();
		RIGHTClick();
		LEFTClick();
	}*/
}

/*Click Left*/
void LEFTClick()
{
	if(PS3.getButtonClick(LEFT))
	{
		left=!left;
	}
	if(left)
	{
		//
	}
	/*else
	{
		Light();
		Start();
		UPClick();
		RIGHTClick();
		DOWNClick();
	}*/
}

/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*#1 L298*****************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*Motor One Enable A ON*/
void motorOneAON()
{
	digitalWrite(One_Enable_A, HIGH);
}

/*Motor One Enable B ON*/
void motorOneBON()
{
	digitalWrite(One_Enable_B, HIGH);
}

/*Motor One Disable A_OFF*/
void motorOneAOFF()
{
	digitalWrite(One_Enable_A, LOW);
	motorOneACoast();
}

/*Motor One Disable B_OFF*/
void motorOneBOFF()
{
	digitalWrite(One_Enable_B, LOW);
	motorOneBCoast();
}

/*Motor One A Forward*/
void motorOneAForward()
{
	digitalWrite(One_Input_1, HIGH);
	digitalWrite(One_Input_2, LOW);
}

/*Motor One A Backward*/
void motorOneABackward()
{
	digitalWrite(One_Input_1, LOW);
	digitalWrite(One_Input_2, HIGH);
}

/*Motor One B Forward*/
void motorOneBForward()
{
	digitalWrite(One_Input_3, LOW);
	digitalWrite(One_Input_4, HIGH);
}

/*Motro One B Backward*/
void motorOneBBackward()
{
	digitalWrite(One_Input_3, HIGH);
	digitalWrite(One_Input_4, LOW);
}

/*Motor One A Coast*/
void motorOneACoast()
{
	digitalWrite(One_Input_1, LOW);
	digitalWrite(One_Input_2, LOW);
}

/*Motor One A Breake*/
void motorOneABreake()
{
	digitalWrite(One_Input_1, HIGH);
	digitalWrite(One_Input_2, HIGH);
}

/*Motor One B Coast*/
void motorOneBCoast()
{
	digitalWrite(One_Input_3, LOW);
	digitalWrite(One_Input_4, LOW);
}

/*Motor One B Breake*/
void motorOneBBreake()
{
	digitalWrite(One_Input_3, HIGH);
	digitalWrite(One_Input_4, HIGH);
}

/*Motor Coas*/
void motorCoast()
{
	motorOneACoast();
	motorOneBCoast();
}

/*Motor Break*/
void motorBreak()
{
	motorOneABreake();
	motorOneBBreake();
}

/*Motor ON*/
void motorON()
{
	motorOneAON();
	motorOneBON();
}

/*Motor OFF*/
void motorOFF()
{
	delay(5);
	motorOneAOFF();
	motorOneBOFF();
}

/*Motor PWM*/
void MotorOnePWM()
{
	/*Go Backward With L2*/
	if ((PS3.getAnalogButton(L2_ANALOG))&&!(PS3.getAnalogButton(R2_ANALOG))&&!(PS3.getButtonPress(CROSS)))
	{
		analogWrite(One_Enable_A, (PS3.getAnalogButton(L2_ANALOG)));
		analogWrite(One_Enable_B, (PS3.getAnalogButton(L2_ANALOG)));
		motorOneABackward();
		motorOneBBackward();
	}

	/*Go Forward With R2*/
	if ((PS3.getAnalogButton(R2_ANALOG))&&!(PS3.getAnalogButton(L2_ANALOG))&&!(PS3.getButtonPress(CROSS)))
	{
		analogWrite(One_Enable_A, (PS3.getAnalogButton(R2_ANALOG)));
		analogWrite(One_Enable_B, (PS3.getAnalogButton(R2_ANALOG)));
		motorOneAForward();
		motorOneBForward();
	}

	/*Rotate Conterclockwise L2+X*/
	if ((PS3.getAnalogButton(L2_ANALOG))&&!(PS3.getAnalogButton(R2_ANALOG))&&(PS3.getButtonPress(CROSS)))
	{
		analogWrite(One_Enable_A, (PS3.getAnalogButton(L2_ANALOG)));
		analogWrite(One_Enable_B, (PS3.getAnalogButton(L2_ANALOG)));
		motorOneAForward();
		motorOneBBackward();
	}

	/*Rotate Clockwise R2+X*/
	if ((PS3.getAnalogButton(R2_ANALOG))&&!(PS3.getAnalogButton(L2_ANALOG))&&(PS3.getButtonPress(CROSS)))
	{
		analogWrite(One_Enable_A, (PS3.getAnalogButton(R2_ANALOG)));
		analogWrite(One_Enable_B, (PS3.getAnalogButton(R2_ANALOG)));
		motorOneABackward();
		motorOneBForward();
	}
	/*Break R2+L2*/
	if ((PS3.getAnalogButton(R2_ANALOG))&&(PS3.getAnalogButton(L2_ANALOG))&&!(PS3.getButtonPress(CROSS)))
	{
		motorON();
		motorBreak();
	}

	/*Motor OFF*/
	motorOFF();
}

/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*#2 L298*****************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*Motor Two Enable A ON*/
void motorTwoAON()
{
	digitalWrite(Two_Enable_A, HIGH);
}

/*Motor Two Enable B ON*/
void motorTwoBON()
{
	digitalWrite(Two_Enable_B,HIGH);
}

/*Motor Two Disable A OFF*/
void motorTwoAOFF()
{
	delay(5);
	digitalWrite(Two_Enable_A, LOW);
	motorTwoACoast();
}

/*Motor Two Disable B OFF*/
void motorTwoBOFF()
{
	delay(5);
	digitalWrite(Two_Enable_B,LOW);
	motorTwoBCoast();
}

/*Motor Two A turn Left*/
void motorTwoAturnLeft()
{
	digitalWrite(Two_Input_1,LOW);
	digitalWrite(Two_Input_2,HIGH);
}

/*Motor Two A turn Right*/
void motorTwoAturnRight()
{
	digitalWrite(Two_Input_1,HIGH);
	digitalWrite(Two_Input_2,LOW);
}

/*Motor Two B UP*/
void motorTwoBUP()
{
	digitalWrite(Two_Input_3,HIGH);
	digitalWrite(Two_Input_4,LOW);
}

/*Motor Two B Down*/
void motorTwoBDown()
{
	digitalWrite(Two_Input_3,LOW);
	digitalWrite(Two_Input_4,HIGH);
}

/*Motor Two A Coast*/
void motorTwoACoast()
{
	digitalWrite(Two_Input_1,LOW);
	digitalWrite(Two_Input_2,LOW);
}

/*Motor Two A Break*/
void motorTwoABreak()
{
	digitalWrite(Two_Input_1,HIGH);
	digitalWrite(Two_Input_2,HIGH);
}

/*Motor Two B Coast*/
void motorTwoBCoast()
{
	digitalWrite(Two_Input_3,LOW);
	digitalWrite(Two_Input_4,LOW);
}

/*Motor Two B Break*/
void motorTwoBBreak()
{
	digitalWrite(Two_Input_3,HIGH);
	digitalWrite(Two_Input_4,HIGH);
}

/*Motor Two AB Coast*/
void motorTwoABCoast()
{
	motorTwoACoast();
	motorTwoBCoast();	
}

/*Motor Two AB Break*/
void motorTwoABBreak()
{
	motorTwoABreak();
	motorTwoBBreak();
}

/*Motor Two OFF*/
void motorTwoOFF()
{
	motorTwoAOFF();
	motorTwoBOFF();
}

/*Turn motor Two A*/
void MotorTwoA()
{
	/*turn Left*/
	if(PS3.getButtonPress(L1))
	{
		motorTwoAON();
		motorTwoAturnLeft();
	}

	/*turn Right*/
	if(PS3.getButtonPress(R1))
	{
		motorTwoAON();
		motorTwoAturnRight();
	}

	/*Motor Two A Coast*/
	if((PS3.getButtonPress(L1))&&(PS3.getButtonPress(R1)))
	{
		motorTwoAON();
		motorTwoACoast();
	}
	
	/*Motor TWO A OFF*/
	motorTwoAOFF();
}

/*Motor Two B*/
void MotorTwoB()
{
	/*UP*/
	if(PS3.getAnalogHat(LeftHatY)<100)
	{
		motorTwoBON();
		motorTwoBUP();
	}

	/*DOWN*/
	if(PS3.getAnalogHat(LeftHatY)>156)
	{
		motorTwoBON();
		motorTwoBDown();
	}

	/*Motor TWO B OFF*/
	motorTwoBOFF();
}

/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*#3 L298*****************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*Motor Three A ON*/
void motorThreeAON()
{
	digitalWrite(Three_Enable_A,HIGH);
}

/*Motor Three A OFF*/
void motorThreeAOFF()
{
	delay(5);
	digitalWrite(Three_Enable_A,LOW);
	motorThreeACoast();
}

/*Motor Three B ON*/
void motorThreeBON()
{
	digitalWrite(Three_Enable_B,HIGH);
}

/*Motor Three B OFF*/
void motorThreeBOFF()
{
	delay(5);
	digitalWrite(Three_Enable_B,LOW);
	motorThreeBCoast();
}

/*Motor Three A Grasp*/
void motorThreeAGrasp()
{
	digitalWrite(Three_Input_1,HIGH);
	digitalWrite(Three_Input_2,LOW);
}

/*Motor Three A Relese*/
void motorThreeARelese()
{
	digitalWrite(Three_Input_1,LOW);
	digitalWrite(Three_Input_2,HIGH);
}

/*Motor Three B UP*/
void motorThreeBUP()
{
	digitalWrite(Three_Input_3,HIGH);
	digitalWrite(Three_Input_4,LOW);
}

/*Motor Three B Down*/
void motorThreeBDown()
{
	digitalWrite(Three_Input_3,LOW);
	digitalWrite(Three_Input_4,HIGH);
}

/*Motor Three A Coast*/
void motorThreeACoast()
{
	digitalWrite(Three_Input_1,LOW);
	digitalWrite(Three_Input_2,LOW);
}

/*Motor Three B Coast*/
void motorThreeBCoast()
{
	digitalWrite(Three_Input_3,LOW);
	digitalWrite(Three_Input_4,LOW);
}

/*Motor Three AB OFF*/
void motorThreeOFF()
{
	motorThreeAOFF();
	motorThreeBOFF();
}

/*Motor Theree A */
void MotorThreeA()
{
	/*Motor Three A Grasp*/
	if(PS3.getButtonPress(R3))
	{
		motorThreeAON();
		motorThreeAGrasp();
	}

	/*Motor Three A Relese*/
	if(PS3.getButtonPress(L3))
	{
		motorThreeAON();
		motorThreeARelese();
	}

	/*Motor Three A OFF*/
	motorThreeAOFF();
}

/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*#4 L298*****************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/

/*Motor Four A Enable*/
void motorFourAON()
{
	digitalWrite(Four_Enable_A,HIGH);
}

/*Motor Four A Disable*/
void motorFourAOFF()
{
	delay(5);
	digitalWrite(Four_Enable_A,LOW);
}

/*Motor Four A joint UP*/
void motorFourAjointUP()
{
	digitalWrite(Four_Input_1,HIGH);
	digitalWrite(Four_Input_2,LOW);
}

/*Motor Four A joint Down*/
void motorFourAjointDown()
{
	digitalWrite(Four_Input_1,LOW);
	digitalWrite(Four_Input_2,HIGH);
}

/*Motor Four A Coast*/
void motorFourACoast()
{
	digitalWrite(Four_Input_1,LOW);
	digitalWrite(Four_Input_2,LOW);
}

/*Motor Four B Enable*/
void motorFourBON()
{
	digitalWrite(Four_Enable_B,HIGH);
}

/*Motor Four B Disable*/
void motorFourBOFF()
{
	delay(5);
	digitalWrite(Four_Enable_B,LOW);
}

/*Motor Four B UP*/
void motorFourBUP()
{
	digitalWrite(Four_Input_3,HIGH);
	digitalWrite(Four_Input_4,LOW);
}

/*Motor Four B Down*/
void motorFourBDown()
{
	digitalWrite(Four_Input_3,LOW);
	digitalWrite(Four_Input_4,HIGH);
}

/*Motor Four B Coast*/
void motorFourBCoast()
{
	digitalWrite(Four_Input_3,LOW);
	digitalWrite(Four_Input_4,LOW);
}

/*Motor Four OFF*/
void motorFourOFF()
{
	motorFourAOFF();
	motorFourACoast();
	motorFourBOFF();
	motorFourBCoast();
}

/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/
/*************************************************************************************************************************************************/