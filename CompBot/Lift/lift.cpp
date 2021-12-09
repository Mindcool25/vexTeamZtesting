#include "lift.h"

/*Lift Functions*/
void moveLift(){
  if(masterController.getDigital(okapi::ControllerDigital::R1)){
    lift.moveVoltage(12000);
  }
  else if(masterController.getDigital(okapi::ControllerDigital::R2)){
    lift.moveVoltage(-12000);
  }
  else{
    lift.moveVoltage(0);
  }

}

void moveLiftAuto(double targetHeight){
  double Height = (lift_right.getPosition() - targetHeight) * -1;

  if(targetHeight > lift_right.getPosition()){
    while(lift_right.getPosition() < targetHeight){
      lift.moveVoltage(10000);
      pros::delay(20);
    }
    lift.moveVoltage(0);
  }
  else if (targetHeight < lift_right.getPosition()){
    while(lift_right.getPosition() > targetHeight){
      lift.moveVoltage(-10000);
      pros::delay(20);
    }
  }
  lift.moveVoltage(0);
}

/*Tilter Functions*/
void moveTilter(){
  if(masterController.getDigital(okapi::ControllerDigital::L1)){
    tilter.moveVoltage(6000);
  }
  else if(masterController.getDigital(okapi::ControllerDigital::L2)){
    tilter.moveVoltage(-6000);
  }
  else {
    tilter.moveVoltage(0);
  }
}

void moveTilterAuto(double angle){
  //-560 deg to 0 deg
  angle *= -4.15;
  if(angle < tilter.getPosition()){
    tilter.moveVoltage(-10000);
    while(tilter.getPosition() > angle){
      pros::delay(20);
    }
    tilter.moveVoltage(0);
  }
  if(angle > tilter.getPosition()){
    tilter.moveVoltage(10000);
    while(tilter.getPosition() < angle){
      pros::delay(20);
    }
    tilter.moveVoltage(0);
  }
}

/*Both*/
void setupLift(){
  lift.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  tilter.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}
