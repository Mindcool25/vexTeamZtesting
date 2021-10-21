#pragma once

#include "main.h"

//define ports
//positive
#define LEFT_MOTOR_FRONT 10
#define RIGHT_MOTOR_BACK 1

//negitive
#define LEFT_MOTOR_BACK 9
#define RIGHT_MOTOR_FRONT 2


//Chassis controller  stuff
std::shared_ptr<okapi::ChassisController> chassisModel;
std::shared_ptr<okapi::ChassisModel> driveTrain;

//create Controller
pros::Controller masterController(pros::E_CONTROLLER_MASTER);

//define inputs
int leftInput;
int rightInput;
