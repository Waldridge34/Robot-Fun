#include <Servo.h>
Servo leftServo;
Servo rightServo;



void setup() {
  // put your setup code here, to run once:
leftServo.attach(6);
rightServo.attach(5);
pinMode(5, OUTPUT); // right Servo
pinMode(6, OUTPUT); // left Servo
pinMode(7, OUTPUT); // Green LED
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  standStill();

  digitalWrite(12, HIGH);
}


void leftTurn() {
  leftServo.write(20);
  rightServo.write(10);
}

void rightTurn() {
  leftServo.write(160);
  rightServo.write(170);
}


void forward() {
  leftServo.write(160);
  rightServo.write(10);
}

void standStill() {
  leftServo.write(87);
  rightServo.write(90);
}

