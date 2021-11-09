#include "drive.h"

void setupDriveMotors(int mode){
  switch(mode){
    case 0:
      rightSide.setBrakeMode(AbstractMotor::brakeMode::coast);
      leftSide.setBrakeMode(AbstractMotor::brakeMode::coast);
      break;
    case 1:
      rightSide.setBrakeMode(AbstractMotor::brakeMode::brake);
      leftSide.setBrakeMode(AbstractMotor::brakeMode::brake);
      break;
    case 2:
      rightSide.setBrakeMode(AbstractMotor::brakeMode::hold);
      leftSide.setBrakeMode(AbstractMotor::brakeMode::hold);
      break;
  }
}

void tankDrive(){
  leftInput = masterController.getAnalog(ControllerAnalog::leftY)*12000;
  rightInput = masterController.getAnalog(ControllerAnalog::rightY)*12000;

  rb_motor.moveVoltage(rightInput);
  rf_motor.moveVoltage(rightInput);

  lb_motor.moveVoltage(leftInput);
  lf_motor.moveVoltage(leftInput);
  //yes
}

void forward(double distance){
  distance *= 60;
  rightSide.tarePosition();
  leftSide.tarePosition();

  rightSide.moveAbsolute(distance, 200);
  leftSide.moveAbsolute(distance, 200);

  if (distance > 0){
    while (rightSide.getPosition() < distance && leftSide.getPosition() < distance){
      pros::delay(20);
    }
  }
  else {
    while (rightSide.getPosition() > distance && leftSide.getPosition() > distance){
      pros::delay(20);
    }
  }

  	pros::delay(50);
}

void turn(double degrees){
  degrees *= 8.205;
  rightSide.tarePosition();
  leftSide.tarePosition();

  rightSide.moveAbsolute(degrees, 200);
  leftSide.moveAbsolute(-degrees, -200);

  if (degrees > 0){
    while (rightSide.getPosition() < degrees && leftSide.getPosition() < degrees){
      pros::delay(20);
    }
  }
  else {
    while (rightSide.getPosition() > degrees && leftSide.getPosition() > degrees){
      pros::delay(20);
    }
  }

  pros::delay(50);
}
