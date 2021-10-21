#include "../include/main.h"
#include "../include/drive.h"

void tankDrive(){
  leftInput = masterController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  rightInput = masterController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  driveTrain->tank(leftInput, rightInput, 0);
}
