#include <Servo.h>

Servo servoBase;
Servo servoArm;
Servo servoForearm;

int vacuumPin = 8;
int servoBasePin = 9;
int servoArmPin = 10;
int servoForearmPin = 11;

int base90 = 300;

int armLowered = 90;
int armRaised = 50;

int forearmLowered = 60;
int forearmRaised = 90;

int forearmSet = 0;
int armSet = 0;
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
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armLowered));
    servoForearm.write(map(i, 0, 100, forearmInitial, forearmLowered));
  }
}

void armUp()
{
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armRaised));
    servoForearm.write(map(i, 0, 100, forearmInitial, forearmRaised));
  }
}

void setup() {
  servoBase.attach(servoBasePin);
  servoBase.write(90);
  servoArm.attach(servoArmPin);
  servoForearm.attach(servoForearmPin);
  pinMode(vacuumPin, OUTPUT);
  
}

void loop()
{
  servoArm.write(armLowered);
  servoForearm.write(forearmLowered);
  delay(1000);
  servoArm.write(armRaised);
  servoForearm.write(forearmRaised);
  delay(5000);
}
