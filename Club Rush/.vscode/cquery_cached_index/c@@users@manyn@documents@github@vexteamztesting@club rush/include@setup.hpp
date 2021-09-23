#include "main.h"

#include <iostream>

#define RIGHT_FRONT_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 1
#define LEFT_FRONT_MOTOR_PORT 9
#define LEFT_BACK_MOTOR_PORT 10

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);

/*
pros::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);

pros::Controller master(pros::E_CONTROLLER_MASTER);
*/

//This code for the okapi is not working. IDK what the problem is.
/*
//create drive chassis through okapi
std::shared_ptr<ChassisController> drive = ChassisControllerBuilder().withMotors(RIGHT_BACK_MOTOR_PORT, -LEFT_BACK_MOTOR_PORT).build();


//Create controller
Controller controller;

//create button object to check for autonomous
ControllerButton autoPressed(ControllerDigital::B);
*/
