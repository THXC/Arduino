// Franzis Arduino
// Codeschloss


int LED_rot=4;
int LED_gruen=5;
int SW1=2;
int SW2=3;
int Buzzer=8;
int x,y,code1,code2,resetTimer=0;


void setup()
{
  
  pinMode(LED_rot,OUTPUT);
  pinMode(LED_gruen,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  
  pinMode(SW1,INPUT);
  digitalWrite(SW1,HIGH);
  
  pinMode(SW2,INPUT);
  digitalWrite(SW2,HIGH);
  Clr_Code();
  
}


void loop()
{

  // Code 1 = 5
    if(!digitalRead(SW1))
    {
      delay(50);
      if(!digitalRead(SW1))
      {
        Blink();
        x++;
        if(x==5)
        {
          code1=true;
        }else code1=false;
        
        do{
        }while(!digitalRead(SW1));
      }
    } 
  
    // Code 2 = 3
    if(!digitalRead(SW2))
    {
      delay(50);
      if(!digitalRead(SW2))
      {
        Blink();
        y++;
        if(y==3)
        {
          code2=true;
        }else code2=false;
        
        do
        { 
          delay(50);
          resetTimer++;
           
          if(resetTimer>50)
          {
            Toggle_Flash();
            Clr_Code();
            break;
          }
        }while(!digitalRead(SW2));
        resetTimer=0;
      }
    } 
  
    if(code1==true&&code2==true)
    {
      digitalWrite(LED_gruen,HIGH);
      Clr_Code();
      delay(5000);
      digitalWrite(LED_gruen,LOW);
    }
    else
    {
      digitalWrite(LED_gruen,LOW);
    }  
}


void Blink(void)
{
  digitalWrite(LED_rot,HIGH);
  tone(Buzzer,500,150);
  delay(200);
  digitalWrite(LED_rot,LOW);
}

void Toggle_Flash(void)
{
  int tog=0;
  for(x=0;x<6;x++)
  {
    if(tog==0)tog=1;else tog=0;
    digitalWrite(LED_rot,tog);
    tone(Buzzer,500,250);
    delay(300);
  }
}

void Clr_Code(void)
{
  x=0;
  y=0;
  code1=0;
  code2=0;
  resetTimer=0;
  delay(1000);  
}


