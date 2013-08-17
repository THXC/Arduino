int Enable_A=5;
int Enable_B=6;
int Input_1=7;
int Input_2=8;
int Input_3=9;
int Input_4=10;

int Poti1=A0;
int Poti2=A1;

int val1, val2, targetval1, targetval2;
int maxval=1012;
int minval=11;
int zeroval=512;

void setup()
{
	Serial.begin(115200);
	Serial.println("REDY");
	pinMode(Enable_A,OUTPUT);
	pinMode(Enable_B,OUTPUT);
	pinMode(Input_1,OUTPUT);
	pinMode(Input_2,OUTPUT);
	pinMode(Input_3,OUTPUT);
	pinMode(Input_4,OUTPUT);
}

void loop()
{
	while(Serial.available() > 0)
	{
		char aChar = Serial.read();
		if (aChar=='1')
		{
			Motor_1_3();
			Serial.println(" Motor_ON and runing 1_3 ");
			Motor_OFF();
		}
		if (aChar=='2')
		{
			Motor_2_4();
			Serial.println(" Motor_ON and runing 2_4 ");
			Motor_OFF();
		}
		if (aChar=='3')
		{
			Potie();
		}
	}
	Motor();
}

void Motor_ON()
{
	digitalWrite(Enable_A,HIGH);
	digitalWrite(Enable_B,HIGH);
}

void Motor_OFF()
{
	delay(10);
	digitalWrite(Enable_A,LOW);
	digitalWrite(Enable_B,LOW);
	Motor_Coast();
	Serial.println(" STOP ");
}

void Motor_Coast()
{
	digitalWrite(Input_1,LOW);
	digitalWrite(Input_2,LOW);
	digitalWrite(Input_3,LOW);
	digitalWrite(Input_4,LOW);
	Potie();
}

void Motor_1_3()
{
	Motor_ON();
	digitalWrite(Input_1,HIGH);
	digitalWrite(Input_2,LOW);
	digitalWrite(Input_3,HIGH);
	digitalWrite(Input_4,LOW);
}

void Motor_2_4()
{
	Motor_ON();
	digitalWrite(Input_1,LOW);
	digitalWrite(Input_2,HIGH);
	digitalWrite(Input_3,LOW);
	digitalWrite(Input_4,HIGH);
}

void Potie()
{
	val1=analogRead(Poti1);
	val2=analogRead(Poti2);
	Serial.print(" Poti ");
	Serial.print(val1);
	Serial.print(" ");
	Serial.println(val2);
}

void Motor()
{
	val1=analogRead(Poti1);
	val2=analogRead(Poti2);
	if ((val1>val2)&&(val1>minval))
	{
		Motor_1_3();
	}
	if ((val1<val2)&&(val1<maxval))
	{
		Motor_2_4();
	}
	if (val1=val2)
	{
		Motor_OFF();
	}
	Serial.print(" POTIE_1= ");
	Serial.print(val1);
	Serial.print(" POTIE_2= ");
	Serial.print(val2);
}

void MotorPWM()
{
	val2=analogRead(Poti2);
	targetval2=(val2/4);
	analogWrite(Enable_A,targetval2);
	digitalWrite(Input_1,HIGH);
	digitalWrite(Input_2,LOW);
	Serial.print(" Delay = ");
	Serial.println(targetval2);
}
