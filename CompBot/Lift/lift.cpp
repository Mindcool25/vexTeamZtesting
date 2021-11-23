#include "lift.h"

void moveLift(){
  while(masterController.getDigital(okapi::ControllerDigital::R1)){
    lift.moveVoltage(6000);
  }
  while(masterController.getDigital(okapi::ControllerDigital::R2)){
    lift.moveVoltage(-6000);
  }
  lift.moveVoltage(0);
}

void moveLiftAuto(double distance){
  lift.tarePosition();
  lift.moveAbsolute(distance, 200);
  if(distance > 0){
    while(lift_left.getPosition() <= distance){
      pros::delay(20);
    }
  }
  else {
    while(lift_left.getPosition() >= distance){
      pros::delay(20);
    }
  }
  pros::delay(50);
}
