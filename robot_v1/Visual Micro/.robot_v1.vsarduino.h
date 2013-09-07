#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Mega 2560 or Mega ADK
#define __AVR_ATmega2560__
#define ARDUINO 105
#define __AVR__
#define F_CPU 16000000L
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void lightON();
void lightOFF();
void Light();
void Start();
void UPClick();
void RIGHTClick();
void DOWNClick();
void LEFTClick();
void motorOneAON();
void motorOneBON();
void motorOneAOFF();
void motorOneBOFF();
void motorOneAForward();
void motorOneABackward();
void motorOneBForward();
void motorOneBBackward();
void motorOneACoast();
void motorOneABreake();
void motorOneBCoast();
void motorOneBBreake();
void motorCoast();
void motorBreak();
void motorON();
void motorOFF();
void MotorOnePWM();
void motorTwoAON();
void motorTwoBON();
void motorTwoAOFF();
void motorTwoBOFF();
void motorTwoAturnLeft();
void motorTwoAturnRight();
void motorTwoBUP();
void motorTwoBDown();
void motorTwoACoast();
void motorTwoABreak();
void motorTwoBCoast();
void motorTwoBBreak();
void motorTwoABCoast();
void motorTwoABBreak();
void motorTwoOFF();
void MotorTwoA();
void MotorTwoB();
void motorThreeAON();
void motorThreeAOFF();
void motorThreeBON();
void motorThreeBOFF();
void motorThreeAGrasp();
void motorThreeARelese();
void motorThreeBUP();
void motorThreeBDown();
void motorThreeACoast();
void motorThreeBCoast();
void motorThreeOFF();
void MotorThreeA();
void motorFourAON();
void motorFourAOFF();
void motorFourAjointUP();
void motorFourAjointDown();
void motorFourACoast();
void motorFourBON();
void motorFourBOFF();
void motorFourBUP();
void motorFourBDown();
void motorFourBCoast();
void motorFourOFF();

#include "C:\Program Files (x86)\Arduino\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\THX\Dropbox\Arduino\robot_v1\robot_v1.ino"
#endif
