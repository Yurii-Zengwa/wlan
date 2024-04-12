#include <Servo.h>

Servo s;

#define PIN_TRIG 13
#define PIN_ECHO 12

void setup() {
  Serial.begin(9600);
  s.attach(10);
  pinMode(2, INPUT_PULLUP);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

}


void loop() {
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  Serial.print("Distance in CM: ");
  Serial.println(duration / 58);

  if((duration/58)<200){
    openDoor();
  }else{
    closeDoor();
  }
  delay(1000);
}
void openDoor(){
  for(int i = 0; i < 160; i=i+10){
    s.write(i);
  }
}
void closeDoor(){
  for(int i = 180; i>=0;i=i-10){
    s.write(i);
  }
}

