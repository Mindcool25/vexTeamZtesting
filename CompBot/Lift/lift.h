#pragma once

#include "../include/main.h"

//motors and motor group
okapi::Motor lift_right(5, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor lift_left(6, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
okapi::MotorGroup lift({lift_right, lift_left});

//functions
void moveLift();
void moveLiftAuto(double distance);
