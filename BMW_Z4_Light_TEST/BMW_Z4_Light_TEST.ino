#define LFR_Gelb	44 
#define LFR_Blue	42
#define LFR_White	40
 
#define LFL_Gelb	38
#define LFL_Blue	36
#define LFL_White	34

#define LRR_Gelb	32
#define LRR_Red1	30
#define LRR_Red2	28

#define LRL_Gelb	26
#define LRL_Red1	24
#define LRL_Red2	22




void setup()
{

  pinMode(LFR_Gelb, OUTPUT);
  pinMode(LFR_Blue, OUTPUT);
  pinMode(LFR_White, OUTPUT);
  
  pinMode(LFL_Gelb, OUTPUT);
  pinMode(LFL_Blue, OUTPUT);
  pinMode(LFL_White, OUTPUT);
  
  pinMode(LRR_Gelb, OUTPUT);
  pinMode(LRR_Red1, OUTPUT);
  pinMode(LRR_Red2, OUTPUT);
  
  pinMode(LRL_Gelb, OUTPUT);
  pinMode(LRL_Red1, OUTPUT);
  pinMode(LRL_Red2, OUTPUT);

}

void loop()
{
	digitalWrite(LFR_Gelb, HIGH);
	delay(250);
	digitalWrite(LFR_Gelb, LOW);
}
