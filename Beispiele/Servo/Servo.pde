// Franzis Arduino
// Servo ansteuern

int servoPin     =  2;     // Servo Pin
int minPulse     =  600;   // minimum servo position
int maxPulse     =  2400;  // maximum servo position
int turnRate     =  1;     // Geschwindigkeit desto größer desto schneller!
int refreshTime  =  20;    // Aktuallisierungs Rate 50Hz = 20ms 1/f

int SW1          =  7;     // Taster 1 links
int SW2          =  6;     // Taster 2 rechts

int centerServo;           // Mittelstellung
int pulseWidth;            // Pulsweite
long lastPulse   = 0;      // Zeit des letzen Impulses speichern


void setup() 
{
  pinMode(servoPin, OUTPUT);  
  pinMode(SW1,INPUT);
  digitalWrite(SW1,HIGH);
  pinMode(SW2,INPUT);
  digitalWrite(SW2,HIGH);
  centerServo = maxPulse - ((maxPulse - minPulse)/2);
  pulseWidth = centerServo;   
}

void loop()
{

  // Wurde ein Taster gedrückt?
  if(!digitalRead(SW1)||!digitalRead(SW2))
  {
    if(!digitalRead(SW1)) {pulseWidth = pulseWidth - turnRate;}
    if(!digitalRead(SW2)) {pulseWidth = pulseWidth + turnRate;}

    // Begrenzung
    if(pulseWidth > maxPulse) {pulseWidth = maxPulse;}
    if(pulseWidth < minPulse) {pulseWidth = minPulse;}
    delay(2);
  }
  
  // Servo ansteurern
  if (millis() - lastPulse >= refreshTime) 
  {
    digitalWrite(servoPin, HIGH);   
    delayMicroseconds(pulseWidth);  
    digitalWrite(servoPin, LOW);    
    lastPulse = millis();           
  }
}


