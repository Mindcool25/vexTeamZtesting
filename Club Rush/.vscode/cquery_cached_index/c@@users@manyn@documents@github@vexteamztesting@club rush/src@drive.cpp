#include "main.h"

//define motor ports
#define RIGHT_BACK_MOTOR_PORT 1
#define RIGHT_FRONT_MOTOR_PORT 2
#define LEFT_BACK_MOTOR_PORT 10
#define LEFT_FRONT_MOTOR_PORT 9

//create a shared_ptr for the logger - not really sure what this does, but it is required
const std::shared_ptr<okapi::Logger>& logger = okapi::Logger::getDefaultLogger();

okapi::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees, logger);

//Create Motor Groups
//Right side motor groups
okapi::MotorGroup rightSide({rf_mtr, rb_mtr}, logger);
//left side motor group
okapi::MotorGroup leftSide({lf_mtr, lb_mtr}, logger);

//Create Controller
okapi::Controller master (okapi::ControllerId::master);

//tank controls
void tank(){
  int rightSideController = master.getAnalog(okapi::ControllerAnalog::rightY);
  int leftSideController = master.getAnalog(okapi::ControllerAnalog::leftY);

  rightSide.moveVoltage(rightSideController * 12000);
  leftSide.moveVoltage(leftSideController * 12000);
}

//arcade controls
void arcade(){

}
