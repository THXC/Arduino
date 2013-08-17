/**
    BasicBot - The basic working bot, using DCMotorBot library.

    Requires DCMotorBot Library available at http://hardwarefun.com/projects/dc-motor-bot
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
 * Constructor
 */
HBridge::HBridge(int hb_num){
	//no room for error :)
}


/**
 * Default Constructor
 */
HBridge::HBridge() {
	//HBridge(1);
    setEnablePins(0, 1);
    setControlPins(2, 3, 4, 5);
}


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
set A diable OFF
*/
void HBridge::motorAOFF(){
	delay(10);
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
	delay(10);
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

/*
forward A
*/
void HBridge::motorAForward(){
	//motorAON();
	digitalWrite(mI1, HIGH);
	digitalWrite(mI2, LOW);
}

/*
forward B
*/
void HBridge::motorBForward(){
	//motorBON();
	digitalWrite(mI3, HIGH);
	digitalWrite(mI4, LOW);
}

/*
forward AB
*/
void HBridge::motorForward(){
	//motorON();
	motorAForward();
	motorBForward();
}

/*
backward A
*/
void HBridge::motorABackward(){
	//motorAON();
	digitalWrite(mI1, LOW);
	digitalWrite(mI2, HIGH);
}

/*
backward B
*/
void HBridge::motorBBackward(){
	//motorBON();
	digitalWrite(mI3, LOW);
	digitalWrite(mI4, HIGH);
}

/*
backward AB
*/
void HBridge::motorBackward(){
	//motorON();
	motorABackward();
	motorBBackward();
}

/*
turn A left
*/
void HBridge::turnALeft(){
	motorAForward();
}

/*
turn B left
*/
void HBridge::turnBLeft(){
	motorBForward();
}

/*
turn A Right
*/
void HBridge::turnARight(){
	motorABackward();
}

/*
turn B Right
*/
void HBridge::turnBRight(){
	motorBBackward();
}

/*
turn left
*/
void HBridge::Left(){
	motorAForward();
	motorBBackward();
}

/*
turn right
*/
void HBridge::Right(){
	motorABackward();
	motorBForward();
}

/*
stop
*/
void HBridge::Stop(){
	motorAOFF();
	motorBOFF();
}

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

/*
move PWM A Backward
*/
void HBridge::movePWMABackward(){
	motorABackward();
}

/*
move PWM B Backward
*/
void HBridge::movePWMBBackward(){
	motorBBackward();
}

/*
move PWM A Forward
*/
void HBridge::movePWMAForward(){
	motorAForward();
}

/*
move PWM B Forward
*/
void HBridge::movePWMBForward(){
	motorBForward();
}

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

/*
turn PWM Left
*/
void HBridge::PWMturnLeft(){
	Left();
}

/*
turn PWM Right
*/
void HBridge::PWMturnRight(){
	Right();
}

/*
move PWM Forward
*/
void HBridge::movePWMForward(){
	motorForward();
}

/*
move PWM Backward
*/
void HBridge::movePWMBackward(){
	motorBackward();
}

/****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************
											Version v1.02											
*****************************************************************************************************
*****************************************************************************************************
*****************************************************************************************************/