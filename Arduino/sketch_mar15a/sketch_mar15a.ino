#include <Servo.h>
#include <NewPing.h>
#include <SharpIR.h>

// The servos
Servo leftServo;
Servo rightServo;
Servo turretServo;

// The IR distance sensor
SharpIR dist_sensor(A3, 25, 93, 20150);
int IRDist;


// The sonar outputs
  NewPing sonar1(8, 8, 40);  
  NewPing sonar2(9, 9, 40);
  NewPing sonar3(10, 10, 40);
  NewPing sonar4(11, 11, 40);

  // The LDRs
  int leftLDR;
  int middleLDR;
  int rightLDR;
  int upLDR;

  // The sonar inputs
  int sonarR1;
  int sonarR2;
  int sonarR3;
  int sonarR4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  leftServo.attach(6);
  rightServo.attach(5);
  turretServo.attach(13);
  pinMode(5, OUTPUT); // right Servo
  pinMode(6, OUTPUT); // left Servo
  pinMode(13, OUTPUT); // turret Servo
  pinMode(7, OUTPUT); // Green LED
  pinMode(12, OUTPUT); // Yellow LED

  pinMode(A0, INPUT); //right LDR
  pinMode(A1, INPUT); // middle LDR
  pinMode(A2, INPUT); // left LDR
  pinMode(A4, INPUT); // up LDR

 


}

void loop() {
  // put your main code here, to run repeatedly:
  standStill();

  turnTurret(180);
}


// turn the turret to an angle
void turnTurret(int angle) {
  turretServo.write(angle);
}

void IRDistance() {
  digitalWrite(12, LOW); // turns IR turret ON
  IRDist = dist_sensor.distance();
  digitalWrite(12, HIGH); // turn IR turret OFF
}


// Reads the value on each of the sonars
void readSonars() {
  sonarR1 = sonar1.ping_cm();
  sonarR2 = sonar2.ping_cm();
  sonarR3 = sonar3.ping_cm();
  sonarR4 = sonar4.ping_cm();  
}

// pivots left
void leftTurn() {
  leftServo.write(20);
  rightServo.write(10);
}

// pivots right
void rightTurn() {
  leftServo.write(160);
  rightServo.write(170);
}

// moves the robot forwards
void forward() {
  leftServo.write(160);
  rightServo.write(10);
}

// makes the robot stop
void standStill() {
  leftServo.write(87);
  rightServo.write(89);
}

// Reads the values for each of the LDRs
void LDRRead() {
  leftLDR = analogRead(A2);
  middleLDR = analogRead(A1);
  rightLDR = analogRead(A0);
  upLDR = analogRead(A4);
}



