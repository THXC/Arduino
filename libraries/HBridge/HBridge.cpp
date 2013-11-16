/**
	u can download this lib from BETA version https://github.com/THXC/Projects/tree/master/HBridge/HBridge
	or latest from https://github.com/THXC/Arduino/tree/master/libraries/HBridge
	and most of the credit goes to MR. Sudar Muthu for delivring a simple lib that u can find on 
	his web page at http://hardwarefun.com/projects/dc-move-bot i have simply rewrite this 
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


#include "HBridge.h"

/**
 * Default Constructor
 */
HBridge::HBridge(int hb_num) {
	//HBridge(1);
    //setEnablePins(0, 1);
    //setControlPins(2, 3, 4, 5);
}

/***************************************************************************************************/

/**
 * Set Enable pins
 */
void HBridge::setEnablePins(byte e1, byte e2) {
    mE1 = e1;
    mE2 = e2;

    pinMode(mE1, OUTPUT);
    pinMode(mE2, OUTPUT);
}

/**
 * Set Control pins
 */
void HBridge::setControlPins(byte I1, byte I2, byte I3, byte I4) {
    mI1 = I1;
    mI2 = I2;
    mI3 = I3;
    mI4 = I4;

    pinMode(mI1, OUTPUT);
    pinMode(mI2, OUTPUT);
    pinMode(mI3, OUTPUT);
    pinMode(mI4, OUTPUT);
}

/***************************************************************************************************/

/*
set  A enable ON
*/
void HBridge::motorAON() {
	digitalWrite(mE1, HIGH);
}

/*
set A disable OFF
*/
void HBridge::motorAOFF(){
	delay(5);
	digitalWrite(mE1, LOW);
	motorACoast();
}

/*
set B enable ON
*/
void HBridge::motorBON(){
	digitalWrite(mE2, HIGH);
}

/*
set B disable OFF
*/
void HBridge::motorBOFF(){
	delay(5);
	digitalWrite(mE2, LOW);
	motorBCoast();
}

/*
set AB enable ON
*/
void HBridge::motorON(){
	motorAON();
	motorBON();
}

/*
set AB disable OFF
*/
void HBridge::motorOFF(){
	motorAOFF();
	motorBOFF();
}

/***************************************************************************************************/

/*
coast A
*/
void HBridge::motorACoast(){
	digitalWrite(mI1, LOW);
	digitalWrite(mI2, LOW);
}

/*
coast B
*/
void HBridge::motorBCoast(){
	digitalWrite(mI3, LOW);
	digitalWrite(mI4, LOW);
}

/***************************************************************************************************/

/*
forward A
*/
void HBridge::moveAForward(){
	//moveAON();
	digitalWrite(mI1, HIGH);
	digitalWrite(mI2, LOW);
}

/*
forward B
*/
void HBridge::moveBForward(){
	//moveBON();
	digitalWrite(mI3, HIGH);
	digitalWrite(mI4, LOW);
}

/*
forward AB
*/
void HBridge::moveForward(){
	//moveON();
	moveAForward();
	moveBForward();
}

/*
backward A
*/
void HBridge::moveABackward(){
	//moveAON();
	digitalWrite(mI1, LOW);
	digitalWrite(mI2, HIGH);
}

/*
backward B
*/
void HBridge::moveBBackward(){
	//moveBON();
	digitalWrite(mI3, LOW);
	digitalWrite(mI4, HIGH);
}

/*
backward AB
*/
void HBridge::moveBackward(){
	//moveON();
	moveABackward();
	moveBBackward();
}

/***************************************************************************************************/

/*
moveAUP
*/
void HBridge::moveAUP(){
	moveAForward();
}

/*
moveADown
*/
void HBridge::moveADown(){
	moveABackward();
}

/*
moveBUP
*/
void HBridge::moveBUP(){
	moveBForward();
}

/*
moveBDown
*/
void HBridge::moveBDown(){
	moveBBackward();
}

/*
moveUP
*/
void HBridge::moveUP(){
	moveAUP();
	moveBUP();
}

/*
moveDown
*/
void HBridge::moveDown(){
	moveADown();
	moveBDown();
}

/***************************************************************************************************/

/*
turn A left
*/
void HBridge::turnALeft(){
	moveAForward();
}

/*
turn B left
*/
void HBridge::turnBLeft(){
	moveBForward();
}

/*
turn A Right
*/
void HBridge::turnARight(){
	moveABackward();
}

/*
turn B Right
*/
void HBridge::turnBRight(){
	moveBBackward();
}

/***************************************************************************************************/

/*
turn left
*/
void HBridge::moveLeft(){
	moveAForward();
	moveBBackward();
}

/*
turn right
*/
void HBridge::moveRight(){
	moveABackward();
	moveBForward();
}

/*
stop
*/
void HBridge::motorStop(){
	motorAOFF();
	motorBOFF();
}

/***************************************************************************************************/

/*
A catch 
*/
void HBridge::ACatch(){
	moveAForward();
}

/*
A drop
*/
void HBridge::ADrop(){
	moveABackward();
}

/*
B Catch
*/
void HBridge::BCatch(){
	moveBForward();
}

/*
B Drop
*/
void HBridge::BDrop(){
	moveBBackward();
}

/*
AB Catch
*/
void HBridge::ABCatch(){
	ACatch();
	BCatch();
}

/*
AB Drop
*/
void HBridge::ABDrop(){
	ADrop();
	BDrop();
}

/***************************************************************************************************/

/*
PWM A
*/
void HBridge::PWMA(int vala){
	analogWrite(mE1, vala);
}

/*
PWM B
*/
void HBridge::PWMB(int valb){
	analogWrite(mE2, valb);
}

/*
PWM
*/
void HBridge::PWM(int val){
	analogWrite(mE1, val);
	analogWrite(mE2, val);
}

/***************************************************************************************************/

/*
move PWM A Backward
*/
void HBridge::movePWMABackward(){
	moveABackward();
}

/*
move PWM B Backward
*/
void HBridge::movePWMBBackward(){
	moveBBackward();
}

/*
move PWM A Forward
*/
void HBridge::movePWMAForward(){
	moveAForward();
}

/*
move PWM B Forward
*/
void HBridge::movePWMBForward(){
	moveBForward();
}

/***************************************************************************************************/

/*
move PWM A Left
*/
void HBridge::movePWMALeft(){
	turnALeft();
}

/*
move PWM A Right
*/
void HBridge::movePWMARight(){
	turnARight();
}

/*
move PWM B Left
*/
void HBridge::movePWMBLeft(){
	turnBLeft();
}

/*
move PWM B Right
*/
void HBridge::movePWMBRight(){
	turnBRight();
}

/***************************************************************************************************/

/*
turn PWM Left
*/
void HBridge::PWMturnLeft(){
	moveLeft();
}

/*
turn PWM Right
*/
void HBridge::PWMturnRight(){
	moveRight();
}

/*
move PWM Forward
*/
void HBridge::movePWMForward(){
	moveForward();
}

/*
move PWM Backward
*/
void HBridge::movePWMBackward(){
	moveBackward();
}

/****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************
											Version v1.07									
*****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************/