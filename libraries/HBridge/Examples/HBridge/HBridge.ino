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
#include <HBridge.h>

HBridge hb1(1, 3, 5, 2, 4, 7, 8);
HBridge hb2(2, 10, 11, 12, 13, 14, 15);

void setup() {

    // initialize bot pins
    hb1.setEnablePins(3, 5);
    hb2.setEnablePins(10, 11);
    hb1.setControlPins(2, 4, 7, 8);
    hb2.setControlPins(12, 13, 14, 15);
}

void loop() {
    hb1.motorAForward();
    hb2.motorBForward();
    hb1.motorABackward();
    hb2.motorBBackward();
 }
