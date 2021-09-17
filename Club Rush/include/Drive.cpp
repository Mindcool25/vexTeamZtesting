#include "main.h"

//define motor & button ports
#define RIGHT_BACK_MOTOR_PORT 1
#define RIGHT_FRONT_MOTOR_PORT 2
#define LEFT_BACK_MOTOR_PORT 10
#define LEFT_FRONT_MOTOR_PORT 9
#define ARCADE_BUTTON_PORT 'h'
#define TANK_BUTTON_PORT 'f'

//create a shared_ptr for the logger - not really sure what this does, but it is required
const std::shared_ptr<okapi::Logger>& logger = okapi::Logger::getDefaultLogger();

//create all motors
okapi::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);

//Create Motor Groups
//Right side motor groups
okapi::MotorGroup rightSide({rf_mtr, rb_mtr}, logger);
//left side motor group
okapi::MotorGroup leftSide({lf_mtr, lb_mtr}, logger);

//Create Controller
okapi::Controller master(okapi::ControllerId::master);

//create buttons
okapi::ADIButton tankDrive(TANK_BUTTON_PORT, false);
okapi::ADIButton arcadeDrive(ARCADE_BUTTON_PORT, false);

//create all other variables
//true - tank active; false - arcade active
bool driveMode;

//tank controls - working
void tank(){
  int rightSideController = master.getAnalog(okapi::ControllerAnalog::rightY);
  int leftSideController = master.getAnalog(okapi::ControllerAnalog::leftY);

  rightSide.moveVoltage(rightSideController * 12000);
  leftSide.moveVoltage(leftSideController * 12000);
}

//arcade controls - not working
void arcade(){
  int power = master.getAnalog(okapi::ControllerAnalog::rightY);
  int turn = master.getAnalog(okapi::ControllerAnalog::rightX);

  rightSide.moveVoltage((power-turn)*12000);
  leftSide.moveVoltage((power+turn)* 12000);
}

//controls what drive type happens
void drive(){
  if(tankDrive.isPressed()){
    driveMode = true;
  }
  else if (arcadeDrive.isPressed()){
    driveMode = false;
  }

  if(driveMode){
    tank();
  }
  else if(!driveMode) {
    arcade();
  }
}


void square(){
  rightSide.moveRelative(360, 12000);
  leftSide.moveRelative(360, 12000);
  if(rightSide.isStopped() && leftSide.isStopped()){
    rightSide.moveRelative(360, 12000);
  }
}
