#include "include/main.h"
#include <iostream>

#define RIGHT_FRONT_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 1
#define LEFT_FRONT_MOTOR_PORT 9
#define LEFT_BACK_MOTOR_PORT 10

//create drive chassis through okapi
std::shared_ptr<ChassisController> drive = ChassisControllerBuilder().withMotors(RIGHT_BACK_MOTOR_PORT, -LEFT_BACK_MOTOR_PORT).build();


//Create controller
Controller controller;

//create button object to check for autonomous
ControllerButton autoPressed(ControllerDigital::B);
