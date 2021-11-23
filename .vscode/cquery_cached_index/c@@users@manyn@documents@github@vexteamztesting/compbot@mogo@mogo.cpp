#include "MOGO.h"

void moveMOGO(){
  while (masterController.getDigital(okapi::ControllerDigital::right)){
    mogoLift.moveVoltage(12000);
  }
  while (masterController.getDigital(okapi::ControllerDigital::left)){
    mogoLift.moveVoltage(-12000);
  }
  mogoLift.moveVoltage(0);
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
