#include <HBridgeI2CI2C.h>
#include <inttypes.h>
#include "Arduino.h"
#include "Wire.h"


/*PCF8574 pins outputs*/


#define mE1		B00000001						// pin 0
#define mE1		B00000010						// pin 1
#define mI1		B00000100						// pin 2
#define mI2		B00001000						// pin 3
#define mI3		B00010000						// pin 4
#define mI4		B00100000						// pin 5
#define mT1		B01000000						// pin 6
#define mT2		B10000000						// pin 7

HBridgeI2C::HBridgeI2C(int hbi2c_Addr)
{
	_Addr = hbi2c_Addr;
}

HBridgeI2C::init(){
	Wire.begin();
}


/***************************************************************************************************/

/*
set  A enable ON
*/
void HBridgeI2C::motorAON() {
	Wire.write(mE1);
}

/*
set A diable OFF
*/
void HBridgeI2C::motorAOFF(){
	delay(10);
	Wire.write(mE1);
	motorACoast();
}

/*
set B enable ON
*/
void HBridgeI2C::motorBON(){
	Wire.write(mE2);
}

/*
set B disable OFF
*/
void HBridgeI2C::motorBOFF(){
	delay(10);
	Wire.write(mE2);
	motorBCoast();
}

/*
set AB enable ON
*/
void HBridgeI2C::motorON(){
	motorAON();
	motorBON();
}

/*
stop
*/
void HBridgeI2C::Stop(){
	motorAOFF();
	motorBOFF();
}

/*
coast A
*/
void HBridgeI2C::motorACoast(){
	Wire.write(mI1);
	Wire.write(mI2);
}

/*
coast B
*/
void HBridgeI2C::motorBCoast(){
	Wire.write(mI3);
	Wire.write(mI4);
}

/*
forward A
*/
void HBridgeI2C::motorAForward(){
	//motorAON();
	Wire.write(mI1);
	Wire.write(mI2);
}

/*
forward B
*/
void HBridgeI2C::motorBForward(){
	//motorBON();
	Wire.write(mI3);
	Wire.write(mI4);
}

/*
forward AB
*/
void HBridgeI2C::motorForward(){
	//motorON();
	motorAForward();
	motorBForward();
}

/*
backward A
*/
void HBridgeI2C::motorABackward(){
	//motorAON();
	Wire.write(mI1);
	Wire.write(mI2);
}

/*
backward B
*/
void HBridgeI2C::motorBBackward(){
	//motorBON();
	Wire.write(mI3);
	Wire.write(mI4);
}

/*
backward AB
*/
void HBridgeI2C::motorBackward(){
	//motorON();
	motorABackward();
	motorBBackward();
}

/*
turn A left
*/
void HBridgeI2C::turnALeft(){
	motorAForward();
}

/*
turn B left
*/
void HBridgeI2C::turnBLeft(){
	motorBForward();
}

/*
turn A Right
*/
void HBridgeI2C::turnARight(){
	motorABackward();
}

/*
turn B Right
*/
void HBridgeI2C::turnBRight(){
	motorBBackward();
}

/*
turn left
*/
void HBridgeI2C::Left(){
	motorAForward();
	motorBBackward();
}

/*
turn right
*/
void HBridgeI2C::Right(){
	motorABackward();
	motorBForward();
}

/****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************
											Version v1.00											
*****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************/