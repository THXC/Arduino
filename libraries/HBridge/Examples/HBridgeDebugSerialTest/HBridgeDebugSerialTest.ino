/**
 * BasicBot - The basic working bot, using DCMotorBot library.
 * 
 * Requires DCMotorBot Library available at http://hardwarefun.com/projects/dc-motor-bot
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
/*debug and testing sketch*/

HBridge hb1;  //the nr 1 its for the HBridge PCB number
HBridge hb2;  //

void setup() {

  // initialize bot pins
  hb1.setEnablePins(0, 1);// OUTPUT PINS / Enable pins
  hb2.setEnablePins(6, 7);// OUTPUT PINS / Control pins
  hb1.setControlPins(2, 3, 4, 5);
  hb2.setControlPins(8, 9, 10, 11);
  Serial.begin(115200);// Serial for quick control and debug 
  Serial.print("RDY");

}

void loop()
{
  while(Serial.available()>0)
  {
    char aChar = Serial.read();
    if(aChar=='1')
    {
      hb1.motorAForward();
      hb1.motorAOFF();
    }
    if(aChar=='2')
    {
      hb1.motorBForward();
      hb1.motorBOFF();
    }
    if(aChar=='3')
    {
      hb1.motorABackward();
      hb1.motorAOFF();
    }
    if(aChar=='4')
    {
      hb1.motorBBackward();
      hb1.motorBOFF();
    }
    if(aChar=='5')
    {
      hb1.Left();
      hb1.motorOFF();
    }
    if(aChar=='6')
    {
      hb1.Right();
      hb1.motorOFF();
    }
    if(aChar=='0')
    {
      hb2.motorAForward();
      hb2.motorAOFF();
    }
    if(aChar=='7')
    {
      hb2.Left();
      hb2.Stop();
    }
    if(aChar=='8')
    {
      hb2.Right();
      hb2.motorOFF();
    }
  }
}

