#include <HBridgeI2C.h>
#include <Wire.h>

/*Basic program to show u how this lib works 
pin0 is connected to input 1
pin1 is connected to input 2
pin2 is connected to input 3
pin3 is connected to input 4
pin4 is connected to Enable1 or EnableA
pin5 is connected to Enable2 or EnableB
pin6 is NC
pin7 is NC
and the default address on my pcf8574ap when pins A0, A1, A2 are connected to GND is 0x38

for more movement see the HBridgeI2C.h file


*/

HBridgeI2C hb;

void setup(){
  hb.begin();
}
void loop(){
  hb.motorAForward();// move motor A forward
  delay(1000);
  hb.Stop();
  
  hb.motorBackward();// move motor A and B Backward
  delay(1000);
  hb.Stop();
  
  hb.Left();// turn motor A left and motor B right 
  delay(5000);
  hb.Stop();
  
  hb.Right();// turn motor A right and motor B left
  delay(2500);
  hb.Stop();  
}
