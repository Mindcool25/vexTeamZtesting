#include "main.h"

//positive
#define LEFT_MOTOR_FRONT 10
#define RIGHT_MOTOR_BACK 1

//negitive
#define LEFT_MOTOR_BACK 9
#define RIGHT_MOTOR_FRONT 2

//create Chassis Controller
//shared_ptr (type ChassisController), name = function to build (ChassisControllerBuilder).add the motors (withMotors)({left set motors}, {right set motors}).add dimensions (withDimensions)({set gearset, set motor to wheel rotation}, {{wheel diameter, mid-tire to mid tire distance}, ticks per revolution}).build();
std::shared_ptr<okapi::ChassisController> mainChassis = ChassisControllerBuilder.addmotors
int leftInput;
int rightInput;

void tank(){

}
