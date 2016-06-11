#include <Servo.h>

Servo servoBase;
Servo servoArm;
Servo servoForearm;

int vacuumPin = 8;
int servoBasePin = 9;
int servoArmPin = 10;
int servoForearmPin = 11;

int base90 = 300;

int armLowered = 0;
int armRaised = 90;

int forearmLowered = 0;
int forearmRaised = 90;

int currBasePos = 0;

void baseTurn(int baseTurnDirection, int baseTurnDegrees)
{
  servoBase.write(90 + baseTurnDirection * 90);
  delay(baseTurnDegrees / 90 * base90);
  servoBase.write(90);
}

void armTurn(int armTurnDegrees)
{
  servoArm.write(armTurnDegrees);
}

void forearmTurn(int forearmTurnDegrees)
{
  servoForearm.write(forearmTurnDegrees);
}

void armDown()
{
  while(servoArm.read() > armLowered || )
}


void setup() {
  servoBase.attach(servoBasePin);
  servoBase.write(90);
  servoArm.attach(servoArmPin);
  servoArm.write(90);
  servoForearm.attach(servoForearmPin);
  pinMode(vacuumPin, OUTPUT);
  baseTurn(1, 360);
  baseTurn(-1, 360);
  armTurn(armRaised);
  armTurn(armLowered);
}

void loop()
{
}
