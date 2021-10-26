#pragma once

#include "../include/main.h"
using namespace okapi;

//define ports
//positive
#define LEFT_MOTOR_FRONT 10
#define RIGHT_MOTOR_BACK 1

//negitive
#define LEFT_MOTOR_BACK 9
#define RIGHT_MOTOR_FRONT 2

//define inputs
float leftInput;
float rightInput;

//define functions
void tankDrive();
void forward(double distance);
