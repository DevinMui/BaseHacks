#include <Servo.h>

Servo servoBase;
Servo servoArm;

int vacuumPin = 8;
int servoBasePin = 9;
int servoArmPin = 10;

int deg90 = 400;

int currBasePos = 0;

void testTurn() {
  servoBase.write(180);
  delay(deg90);
  servoBase.write(90);
}

void baseTurn(int baseTurnDirection, int baseTurnDegrees)
{
  servoBase.write(90 + baseTurnDirection * 90);
  delay(1600);
  servoBase.write(90);
}

void setup() {
  servoBase.attach(servoBasePin);
  servoBase.write(90);
  servoArm.attach(servoArmPin);
  servoArm.write(90);
  pinMode(vacuumPin, OUTPUT);
  baseTurn(1, 360);
}

void loop()
{
}
