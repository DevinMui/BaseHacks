#include <Servo.h>
String hello = "";
Servo servoBase;
Servo servoArm;
Servo servoForearm;
Servo servoVacuum;

int servoBasePin = 9;
int servoArmPin = 10;
int servoForearmPin = 11;
int servoVacuumPin = 6;

int base90 = 200;

int armLoweredHard = 115;
int armLowered = 95;
int armRaised = 50;

int forearmLowered = 60;
int forearmRaised = 120;

int vacuumLowered = 150;
int vacuumRaised = 0;

void baseTurn(int baseTurnDirection, int baseTurnDegrees)
{
  servoBase.write(90 + (baseTurnDirection * -4));
  delay(4 * baseTurnDegrees / 90 * base90);
  //delay(3000);
  servoBase.write(90);
}
void baseNTurn(int baseTurnDegrees)
{
  servoBase.write(94);
  delay(11 * baseTurnDegrees / 90 * base90);
  //delay(3000);
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

void armDownHard()
{
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armLoweredHard));
    //servoForearm.write(map(i, 0, 100, forearmInitial, forearmLowered));
    delay(20);
  }
  servoArm.write(armLoweredHard);
  //servoForearm.write(forearmLowered);
  delay(500);
}
void armDown()
{
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armLowered));
    //servoForearm.write(map(i, 0, 100, forearmInitial, forearmLowered));
    delay(20);
  }
  servoArm.write(armLowered);
  //servoForearm.write(forearmLowered);
  delay(500);
}
void armUp()
{
  int armInitial = servoArm.read();
  int forearmInitial = servoForearm.read();
  for(int i = 0; i <= 100; i++)
  {
    servoArm.write(map(i, 0, 100, armInitial, armRaised));
    //servoForearm.write(map(i, 0, 100, forearmInitial, forearmRaised));
    delay(20);
  }
  servoArm.write(armRaised);
  //servoForearm.write(forearmRaised);
  delay(500);
}

void vacuumOn()
{
  servoVacuum.attach(servoVacuumPin);
  servoVacuum.write(vacuumLowered);
  delay(500);
}

void vacuumOff()
{
  servoVacuum.attach(servoVacuumPin);
  servoVacuum.write(vacuumLowered - 20);
  delay(500);
  
}

void mainRoutine()
{
  //Initial Setup
  vacuumOff();
  //Grab first slice of bread
  armUp();
  baseTurn(1, 100);
  armDownHard();
  vacuumOn();
  //Drop first slice of bread
  armUp();
  baseNTurn(400); // off by 75 for some reason
  armDown();
  vacuumOff();
  //Grab meat
  armUp();
  baseTurn(1, 250);
  armDownHard();
  vacuumOn();
  //Drop meat
  armUp();
  baseNTurn(540);
  armDown();
  vacuumOff();
  armUp();
  baseTurn(1, 175);
  armDownHard();
  vacuumOn();
  //Drop first slice of bread
  armUp();
  baseNTurn(400); // off by 75 for some reason
  armDown();
  vacuumOff();
  
}



void setup() {
  Serial.begin(9600);
  servoBase.attach(servoBasePin);
  //servoBase.write(90);
  servoArm.attach(servoArmPin);
  servoForearm.attach(servoForearmPin);
  servoVacuum.attach(servoVacuumPin);
  /*servoVacuum.write(vacuumLowered);
  delay(3000);
  servoVacuum.write(vacuumLowered - 20);*/
  
  //mainRoutine();
  //armUp();
  //baseTurn(-.1, 90 / 4);
  //baseNTurn(180);
}

void loop()
{
  Serial.print(Serial.read());
  Serial.println();
  // checks value from server/connected computer
  if(Serial.parseInt() == 1){
    mainRoutine();
  }
}
