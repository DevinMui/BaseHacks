#include <Servo.h>

Servo servoBase;
Servo servoArm;

int currBasePos = 0;

void setup() {
  servoBase.attach(9);
  servoBase.write(90);
  servoArm.attach(10);
  servoArm.write(90);
}

void loop() {
  
}
