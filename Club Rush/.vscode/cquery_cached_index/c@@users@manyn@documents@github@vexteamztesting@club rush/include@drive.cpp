#include "main.h"

//Function List
void tank();
void arcade();
void drive();
void square();
void forward(int delay);
void turn(int degrees);

//define motor & button ports
#define RIGHT_BACK_MOTOR_PORT 1
#define RIGHT_FRONT_MOTOR_PORT 2
#define LEFT_BACK_MOTOR_PORT 10
#define LEFT_FRONT_MOTOR_PORT 9
#define ARCADE_BUTTON_PORT 'h'
#define TANK_BUTTON_PORT 'f'
#define BUMPER_BUTTONS 'a'
#define TANK_DIODE_PORT 'g'
#define ARCADE_DIODE_PORT 'e'

//create a shared_ptr for the logger - not really sure what this does, but it is required
const std::shared_ptr<okapi::Logger>& logger = okapi::Logger::getDefaultLogger();

//create all motors
okapi::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);
okapi::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees, logger);

//Create Motor Groups & ChassisController
//Right side motor groups
okapi::MotorGroup rightSide({rf_mtr, rb_mtr}, logger);
//left side motor group
okapi::MotorGroup leftSide({lf_mtr, lb_mtr}, logger);

//Create Controller
okapi::Controller master(okapi::ControllerId::master);

//create buttons
okapi::ADIButton tankDrive(TANK_BUTTON_PORT, false);
okapi::ADIButton arcadeDrive(ARCADE_BUTTON_PORT, false);
okapi::ADIButton bumperButtons(BUMPER_BUTTONS, false);

//create all other variables
//true - tank active; false - arcade active
bool driveMode;
//create tank diode
pros::ADIDigitalOut tankDiode(TANK_DIODE_PORT);
//create arcade diode
pros::ADIDigitalOut arcadeDiode(ARCADE_DIODE_PORT);
//create potentiometer
pros::ADIAnalogIn speedControl('c');
//create speed value
int speedValue;

//tank controls
void tank(){
  //Get controller values
  int rightSideController = master.getAnalog(okapi::ControllerAnalog::rightY);
  int leftSideController = master.getAnalog(okapi::ControllerAnalog::leftY);

  //move @ values times 12000 to get the voltage
  rightSide.moveVoltage(rightSideController * speedValue);
  leftSide.moveVoltage(leftSideController * speedValue);
}

//arcade controls
void arcade(){
  //get controller values
  int power = master.getAnalog(okapi::ControllerAnalog::rightY);
  int turn = master.getAnalog(okapi::ControllerAnalog::rightX);

  //move rightSide at power - turn & leftSide @ turn + power
  rightSide.moveVoltage((power-turn)*speedValue);
  leftSide.moveVoltage((power+turn)* speedValue);

}

//controls what drive type happens - arcade vs tank
void drive(){
  //check if tank drive button is pressed
  if(tankDrive.isPressed()){
    //change drive mode variable
    driveMode = true;

    //Change Diodes
    tankDiode.set_value(1);
    arcadeDiode.set_value(0);
  }
  //check if arcade drive button is pressed
  else if (arcadeDrive.isPressed()){
    //change drive mode variable
    driveMode = false;

    //Change Diodes
    tankDiode.set_value(0);
    arcadeDiode.set_value(1);
  }

  //check which mode is active and run that function.
  if(driveMode){
    tank();
  }
  else if(!driveMode) {
    arcade();
  }
}


void square(){
  //set brake mode to hold position
  leftSide.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
  rightSide.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

  //loop forward, turn repeat - make a square
  for(int i = 0; i < 4; i++){
    forward(150);
    pros::delay(1000);
    turn(-90);
    pros::delay(1000);
  }
}

//Function to Move forward certain distance
void forward(int distance){
  //if the distance is positive
  if(distance > 0){
    //reset positions
    rightSide.tarePosition();
    leftSide.tarePosition();

    //move distance at 200 speed (max speed for green motors)
    rightSide.moveAbsolute(distance, 200);
    leftSide.moveAbsolute(distance+15, 200);

    //delay until position is correct
    while(rightSide.getPosition() < distance){
      pros::delay(10);
    }
  }
  //if the distance is negitive
  else {
    //reset positions
    rightSide.tarePosition();
    leftSide.tarePosition();

    //move distance at 200 speed (max speed for green motors)
    rightSide.moveAbsolute(distance, -200);
    leftSide.moveAbsolute(distance, -200);

    //delay until position is correct
    while(rightSide.getPosition() > distance){
      pros::delay(10);
    }
  }
}

//Function to turn certain degrees
void turn(int degrees){
  //if degrees are positive
  if(degrees > 0){
    //turn(90) isn't perfect 90, have to add a certain amount
    degrees = degrees + 22.5;

    //reset motor position
    rightSide.tarePosition();
    leftSide.tarePosition();

    //turn right side positive, left side negative
    rightSide.moveRelative(degrees, 200);
    leftSide.moveRelative(-degrees, -200);

    //delay until position is good
    while(rightSide.getPosition() < degrees){
      pros::delay(10);
    }
  }
  //if degrees are negitive
  else if(degrees < 0){
    //turn(90) isn't perfect 90, have to subtract a certain amount
    degrees -= 25;

    //reset motor position
    rightSide.tarePosition();
    leftSide.tarePosition();

    //turn right side positive, left side negative
    rightSide.moveRelative(degrees, 200);
    leftSide.moveRelative(-degrees, 200);

    //delay until position is good
    while(rightSide.getPosition() > degrees){
      pros::delay(10);
    }
  }
}
