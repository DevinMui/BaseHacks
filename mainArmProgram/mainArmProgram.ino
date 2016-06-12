#include <Servo.h>

Servo servoBase;
Servo servoArm;
Servo servoForearm;

int vacuumPin = 8;
int servoBasePin = 9;
int servoArmPin = 10;
int servoForearmPin = 11;

int base90 = 250;

int armLowered = 95;
int armRaised = 50;

int forearmLowered = 60;
int forearmRaised = 90;

int forearmSet = 0;
int armSet = 0;
int currBasePos = 0;

void baseTurn(int baseTurnDirection, int baseTurnDegrees)
{
  servoBase.write(90 + (baseTurnDirection * -45));
  delay(2 * baseTurnDegrees / 90 * base90);
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
    delay(20);
  }
  servoArm.write(armLowered);
  servoForearm.write(forearmLowered);
  delay(500);
}

void armUp()
{
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armRaised));
    servoForearm.write(map(i, 0, 100, forearmInitial, forearmRaised));
    delay(20);
  }
  servoArm.write(armRaised);
  servoForearm.write(forearmRaised);
  delay(500);
}

void vacuumOn()
{
  digitalWrite(vacuumPin, HIGH);
}

void vacuumOff()
{
  digitalWrite(vacuumPin, LOW);
}

void mainRoutine()
{
  //Initial Setup
  vacuumOff();
  //Grab first slice of bread
  armUp();
  baseTurn(1, 90);
  armDown();
  vacuumOn();
  //Drop first slice of bread
  armUp();
  baseTurn(-1, 180);
  armDown();
  vacuumOff();/*
  //Grab meat
  armUp();
  baseTurn(1, 120);
  armDown();
  vacuumOn();
  //Drop meat
  armUp();
  baseTurn(-1, 210);
  armDown();
  vacuumOff();
  //Grab cucumber
  armUp();
  baseTurn(1, 150);
  armDown();
  vacuumOn();
  //Drop cucumber
  armUp();
  baseTurn(-1, 240);
  armDown();
  vacuumOff();
  //Grab second slice of bread
  armUp();
  baseTurn(1, 90);
  armDown();
  vacuumOn();
  //Drop second slice of bread
  armUp();
  baseTurn(-1, 180);
  armDown();
  vacuumOff();*/
}



void setup() {
  servoBase.attach(servoBasePin);
  servoBase.write(90);
  servoArm.attach(servoArmPin);
  servoForearm.attach(servoForearmPin);
  pinMode(vacuumPin, OUTPUT);
  mainRoutine();
}

void loop()
{
}
