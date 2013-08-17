/**
	u can download this lib from BETA version https://github.com/THXC/Projects/tree/master/HBridge/HBridge
	or latest from https://github.com/THXC/Arduino/tree/master/libraries/HBridge
	and most of the credit goes to MR. Sudar Muthu for delivring a simple lib that u can find on 
	his web page at http://hardwarefun.com/projects/dc-motor-bot i have simply rewrite this 
	to match my requirements :)
	Sincerely T.H.X. and have fun using this lib
*/

/*
 * Copyright 2012  Sudar Muthu  (http://hardwarefun.com)
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 */



#ifndef HBridge_H
#define HBridge_H

// Compatibility for Arduino 1.0

#if ARDUINO >= 100
    #include "Arduino.h"
#else    
    #include "WProgram.h"
#endif

class HBridge {

public:

    // constructor
    HBridge(); // empty constructor
    HBridge(int hb_num); // constructor

	//void HBridge(int hb_num);
    void setEnablePins(byte el, byte e2);
    void setControlPins(byte I1, byte I2, byte I3, byte I4);
  
    // movement functions
    void motorAON();
	void motorAOFF();
	void motorBON();
	void motorBOFF();
	void motorON();
	void motorOFF();

	//coast
	void motorACoast();
	void motorBCoast();

	//move
	void motorAForward();
	void motorBForward();
	void motorForward();
	void motorABackward();
	void motorBBackward();
	void motorBackward();

	//move A left and B right /-/ A right and B left
	void turnALeft();
	void turnBLeft();
	void turnARight();
	void turnBRight();

	//move AB left or right
	void Left();
	void Right();
	void Stop();

	//PWM
	void PWMA(int vala);
	void PWMB(int valb);
	void PWM(int val);

	void movePWMAForward();
	void movePWMBForward();
	void movePWMABackward();
	void movePWMBBackward();
	void movePWMForward();
	void movePWMBackward();

	void movePWMALeft();
	void movePWMARight();
	void movePWMBLeft();
	void movePWMBRight();

	void PWMturnLeft();
	void PWMturnRight();

private:

    int hb_num;
	int vala;
	int valb;
	int val;

    // enable pins
    byte mE1;
    byte mE2;

    // Control Pins
    byte mI1;
    byte mI2;
    byte mI3;
    byte mI4;
};

#endif
/****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************
											Version v1.02										
*****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************/