/*Note: This code has been tested under Arduino IDE 1.8.3
 Stepper Motor Driving
 
 This program drives a unipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
  */
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
char a;
char b;
void loop() {

a=Serial.read();
if(Serial.available())
{
  b=a;
}

Serial.println(b);
if(b=='a')
{
   int i=0;
  //revolve one revolution clockwise
  for(i=0;i<512;i++){
    if(b=='c')
    {
      break;
    }
  clockwiserotate();
  }  
            // wait for a second
 //revolve one revolution counterclockwise
// for(i=0;i<512;i++){
  //counterclockwiserotate();}
  //delay(1000);              // wait for a second
}

if(b=='c')
{
  digitalWrite(8,LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

}
void clockwiserotate() { //revolve clockwise
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}
void counterclockwiserotate() { //revolve counterclockwise
  step1();
  step7();
  step6();
  step5();
  step4();
  step3();
  step2();
  step1();
}
void step1(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step2(){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step3(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step4(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step5(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step6(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(2);
}
void step7(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2);
}
void step8(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2);
}
