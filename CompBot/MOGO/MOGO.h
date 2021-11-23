#pragma once

#include "../include/main.h"

okapi::Motor mogoLift(20, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);

void moveMOGO();
void moveMOGOAutoUp();
void moveMOGOAutoDown();
void MOGOShake();
