/* drive.cpp
This file defines motors and sets them up. It also creates the auto forward and turn distance
functions and tank drive layout.
*/

#include "drive.h"

//sets up motor brake mode
void setupDriveMotors(int mode){
  direction = 1;
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

//Tank drive contolled by left and right sticksa
void tankDrive(){
  if(masterController.getDigital(ControllerDigital::down) && direction == 1){
    direction = -1;
    pros::delay(100);
  }
  else if(masterController.getDigital(ControllerDigital::up) && direction ==-1){
    direction = 1;
    pros::delay(100);
  }

  if(direction == 1){
    leftInput = masterController.getAnalog(ControllerAnalog::leftY)*12000*1;
    rightInput = masterController.getAnalog(ControllerAnalog::rightY)*12000*1;
  }
  else if(direction == -1){
      rightInput = masterController.getAnalog(ControllerAnalog::leftY)*12000*-1;
      leftInput = masterController.getAnalog(ControllerAnalog::rightY)*12000*-1;
  }

  std::cout << direction << std::endl;

  rb_motor.moveVoltage(rightInput);
  rf_motor.moveVoltage(rightInput);

  lb_motor.moveVoltage(leftInput);
  lf_motor.moveVoltage(leftInput);

}

//auto forward function - parameter is in inches
void forward(double distance){
  double dis = distance;
  dis *= 60;
  rightSide.tarePosition();
  leftSide.tarePosition();

  rightSide.moveAbsolute(dis, 600);
  leftSide.moveAbsolute(dis, 600);

  if (dis > 0){
    while (rightSide.getPosition() < dis && leftSide.getPosition() < dis){
      pros::delay(20);
    }
  }
  else {
    while (rightSide.getPosition() > dis && leftSide.getPosition() > dis){
      pros::delay(20);
    }
  }

  	pros::delay(50);
}

//auto turn function - parameter is in degrees
void turn(double degrees){
  degrees *= -8.205;
  rightSide.tarePosition();
  leftSide.tarePosition();

  rightSide.moveAbsolute(degrees, 600);
  leftSide.moveAbsolute(-degrees, -600);

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
