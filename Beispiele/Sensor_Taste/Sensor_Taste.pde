// Franzis Arduino
// Sensor Taste

int LED=13;
int Sensor=0;
int Flag1,Flag2,tog=0;


void setup()
{
  pinMode(LED,OUTPUT);  
}


void loop()
{
 
 if((analogRead(Sensor)>50)&&(!Flag2))
 {
   delay(50);
   if((analogRead(Sensor)>50)&&(!Flag2))
   {
     if(!tog)tog=1;else tog=0;
     Flag1=tog;
     Flag2=1;
   }
 }
 else
 {
   if((analogRead(Sensor)<5)&&(Flag2))
   {
     delay(50);
     if((analogRead(Sensor)<5)&&(Flag2))
     {
       Flag2=0;
     }
   }
 }
 
 if(!Flag1)digitalWrite(LED,LOW);
 if(Flag1)digitalWrite(LED,HIGH);
 
}


