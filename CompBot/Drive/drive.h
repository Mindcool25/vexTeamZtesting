#pragma once

#include "../include/main.h"
using namespace okapi;

//define ports
//positive
#define LEFT_MOTOR_FRONT 1
#define RIGHT_MOTOR_BACK 10

//negitive
#define LEFT_MOTOR_BACK 2
#define RIGHT_MOTOR_FRONT 9

//define motors
Motor rb_motor(RIGHT_MOTOR_BACK, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor rf_motor(RIGHT_MOTOR_FRONT, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor lb_motor(LEFT_MOTOR_BACK, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor lf_motor(LEFT_MOTOR_FRONT, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

//controller
Controller masterController(ControllerId::master);

//Chassis controller  stuff
//ignore error - it compiles fine
//std::shared_ptr<okapi::ChassisController> chassisModel = okapi::ChassisControllerBuilder().withMotors({lb_motor, lf_motor}, {rb_motor, rf_motor}).withDimensions({okapi::AbstractMotor::gearset::blue, 1}, {{4_in, 14.5_in}, 900}).build();
//std::shared_ptr<okapi::ChassisModel> driveTrain = chassisModel->getModel();

//define inputs
float leftInput;
float rightInput;

//define functions
void tankDrive();
void forward(double distance);
