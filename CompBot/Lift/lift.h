#pragma once

#include "../include/main.h"

//motors and motor group
okapi::Motor lift_right(5, false, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lift_left(6, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup lift({lift_right, lift_left});


okapi::Motor tilter(18, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

//functions
void moveLift();
void setupLift();
void moveLiftAuto(double Height);
void moveTilter();
void moveTilterAuto(double);

enum Height{HighLift = 900, Mid_HighLift = 675, MediumLift = 450, Mid_LowLift = 225, LowLift = 0};
