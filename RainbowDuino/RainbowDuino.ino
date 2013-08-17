/*

 Rainbowduino v3.0 Library examples : 3D Plasma

*/

#include <Rainbowduino.h>

// HSV to RGB array

unsigned char RED[3] = {255,0,0};

unsigned char GREEN[3] = {0,255,0};

unsigned char BLUE[3] = {0,0,255};

unsigned char plasma[4][4][4];

void setup()
{
  Rb.init(); //initialize Rainbowduino driver
}

unsigned char x,y,z,colorshift=0;

void loop()
{
for(x=0;x<4;x++)  
{
 for(y=0;y<4;y++)  
 {
  for(z=0;z<4;z++)
    {
     Rb.setPixelZXY(z,x,y,(RED[plasma[x][y][z] + colorshift]),(GREEN[plasma[x][y][z] + colorshift]),(BLUE[plasma[x][y][z] + colorshift])); //uses R, G and B color bytes
    }
 }
}
 delay(150);
 colorshift=  colorshift + 1;
}