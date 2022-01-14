#include "MOGO.h"

void moveMOGO(){
  if (masterController.getDigital(okapi::ControllerDigital::L1)){
    mogoLift.moveVoltage(12000);

  }
  else if (masterController.getDigital(okapi::ControllerDigital::L2
  )){
    mogoLift.moveVoltage(-12000);
  }
  else {
    mogoLift.moveVoltage(0);
  }
}

void moveMOGOAutoUp(){
  mogoLift.moveVoltage(-11000);
  pros::delay(300);
  mogoLift.moveVoltage(0);
}

void moveMOGOAutoDown(){
  mogoLift.moveVoltage(11000);
  pros::delay(200);
  mogoLift.moveVoltage(0);
}

void MOGOShake(){
  mogoLift.moveVoltage(11000);
  pros::delay(200);
  mogoLift.moveVoltage(-11000);
  pros::delay(100);
  mogoLift.moveVoltage(12000);
  pros::delay(100);
  mogoLift.moveVoltage(-11000);
  pros::delay(100);
  mogoLift.moveVoltage(12000);
}
