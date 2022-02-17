#pragma once
#include "../include/main.h"

Motor mogoLift(RIGHT_MOTOR_BACK, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void moveMOGO();
void moveMOGOAutoUp();
void moveMOGOAutoDown();
void MOGOShake();
