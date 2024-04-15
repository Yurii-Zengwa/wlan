#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myLCD (0x27,16,2);
LiquidCrystal_I2C myLCD2 (0x27,16,2);

#include <ESP32Servo.h>
#include <ToneESP32.h>
int value = 0;
Servo myServo;

byte Anything[8] = {
  0b00110,
  0b01010,
  0b10110,
  0b10100,
  0b01010,
  0b10001,
  0b00111,
  0b10011
};
byte Anything2[8] = {
  0b00110,
  0b00001,
  0b00101,
  0b10101,
  0b11001,
  0b11011,
  0b11001,
  0b11111
};



int notes[] = { 
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0, 
  NOTE_G7, 0, 0,  0, 
  NOTE_G6, 0, 0, 0, 
 
  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 
 
  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0, NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0, 
 
  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 
 
  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0, NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0 
}; 
 
int durations[] = { 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
 
  222, 222, 222, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
 
  222, 222, 222, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
  166, 166, 166, 166, 
};

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  myServo.attach(4);
  myLCD.init();
  myLCD.backlight();
  myLCD2.init();
  myLCD2.backlight();
  myLCD.setCursor(0,1);
  myLCD.print("Hello world");

}

void loop() { 
  
  myLCD.createChar(0,Anything);
  myLCD.setCursor(0,0);
  myLCD.write(0);
  myLCD2.createChar(1,Anything2);
  myLCD2.setCursor(1,0);
  myLCD2.write(1);


if(Serial.available()>0){
    value = Serial.parseInt();
    Serial.println(value);
    myServo.write(byte(value));

  }
 buz();
}

void buz(){
  for(int i = 0; i <78; i++ ){
 tone(0, notes[i], durations[i]);
  }
 
}
