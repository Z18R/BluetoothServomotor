#include <Servo.h>

Servo myservo;

const int Pin = 9; // myservo pin3 PWM

char Text;

String Spilt;

String angle;

int pos = 0; // variable to store the servo position

int k1;

void setup() {

Serial.begin(9600);

pinMode (Pin, OUTPUT);

myservo.attach(Pin);

}

void loop() {

if(Serial.available())

{

Text = Serial.read();

Spilt = Spilt + Text;

if (Text == '*') {

Serial.println(Spilt);

Spilt = Spilt.substring(0, Spilt.length() - 1); // Delete last char *

k1 = Spilt.indexOf('*');

angle = Spilt.substring(0, k1);

myservo.write(angle.toInt());

delay(15);

Spilt = "";

}

}

} 
