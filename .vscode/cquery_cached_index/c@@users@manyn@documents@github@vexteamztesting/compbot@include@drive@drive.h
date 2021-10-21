#pragma once

#include "../main.h"
using namespace okapi;

//define ports
//positive
#define LEFT_MOTOR_FRONT 10
#define RIGHT_MOTOR_BACK 1

//negitive
#define LEFT_MOTOR_BACK 9
#define RIGHT_MOTOR_FRONT 2


//Chassis controller  stuff
//ignore error - it compiles fine
std::shared_ptr<okapi::ChassisController> chassisModel = okapi::ChassisControllerBuilder().withMotors({LEFT_MOTOR_BACK, -LEFT_MOTOR_FRONT}, {-RIGHT_MOTOR_BACK, RIGHT_MOTOR_FRONT}).withDimensions({okapi::AbstractMotor::gearset::blue, 1}, {{4_in, 14.5_in}, 900}).build();
std::shared_ptr<okapi::ChassisModel> driveTrain = chassisModel->getModel();

//create Controller
pros::Controller masterController(pros::E_CONTROLLER_MASTER);

//define inputs
int leftInput;
int rightInput;

//define functions
void tankDrive();
void forward(double distance);
