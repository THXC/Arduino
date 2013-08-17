#include <HBridge.h>

HBridge hb1(1);

void setup(){
  Serial.begin(115200);
  hb1.setEnablePins(3,5);
  hb1.setControlPins(2, 4, 7, 8);
  Serial.print("RDY"); 
}

void loop(){
  while(Serial.available()>0)
  {
    char ar = Serial.read();
    if(ar=='1')
    {
      hb1.motorOFF();
    }
  }
  hb1.PWM(analogRead(A1));
  hb1.movePWMForward();
  Serial.println(analogRead(A1));
}

