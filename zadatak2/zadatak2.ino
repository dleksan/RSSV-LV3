
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
}
char a;
char b;
void loop() {
  // put your main code here, to run repeatedly:
a=Serial.read();
if(Serial.available())
{
  b=a;
}

if(b=='a')
{
    if(sonar.ping_cm()>50)
  {
    delay(300); 
    digitalWrite(4,HIGH); 
    delay(300); 
    digitalWrite(4,LOW); 
      
  }
  Serial.println("Debug line");

  if(sonar.ping_cm()>25 && (sonar.ping_cm()<50))
    delay(3*sonar.ping_cm()); 
    digitalWrite(4,HIGH); 
    delay(3*sonar.ping_cm()); 
    digitalWrite(4,LOW);

  if(sonar.ping_cm()<=25 && (sonar.ping_cm()>=10))
  {
    delay(3*sonar.ping_cm()); 
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH); 
    digitalWrite(6,HIGH);  
    delay(3*sonar.ping_cm()); 
    digitalWrite(4,LOW);
    digitalWrite(7,LOW); 
    digitalWrite(6,LOW);  
    
  }
}
if(b=='c')
{
    digitalWrite(4,LOW);
    digitalWrite(7,LOW); 
    digitalWrite(6,LOW);  
}

delay(100);
}
