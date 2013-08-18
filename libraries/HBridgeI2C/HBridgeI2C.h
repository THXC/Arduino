#ifndef HBridgeI2C_h
#define HBridgeI2C_h

#include<inttypes.h>
#include<Wire.h>


// Compatibility for Arduino 1.0

#if ARDUINO >= 100
    #include "Arduino.h"
#else    
    #include "WProgram.h"
#endif

class HBridgeI2C {

public:

	//constructor
	HBridgeI2C();
	HBridgeI2C(int hbi2c_Addr);

	void init();

    // movement functions
    void motorAON();
	void motorAOFF();
	void motorBON();
	void motorBOFF();
	void motorON();

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

private:

    int _Addr;

};

#endif
/****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************
											Version v1.00									
*****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************/