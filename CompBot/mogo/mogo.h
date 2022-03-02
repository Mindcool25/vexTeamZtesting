#pragma once
#include "../include/main.h"

Motor mogoLift(20, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void moveMOGO();
void moveMOGOAutoUp();
void moveMOGOAutoDown();
void MOGOShake();
