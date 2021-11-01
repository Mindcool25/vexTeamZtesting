#include "../include/main.h"
#include "drive.h"

void tankDrive(){
  leftInput = masterController.getAnalog(ControllerAnalog::leftY)*12000;
  rightInput = masterController.getAnalog(ControllerAnalog::rightY)*12000;

  rb_motor.moveVoltage(rightInput);
  rf_motor.moveVoltage(rightInput);

  lb_motor.moveVoltage(leftInput);
  lf_motor.moveVoltage(leftInput);
  //yes
}

void forward(double distance){
  rb_motor.moveVoltage(12000);
  rf_motor.moveVoltage(12000);
  lb_motor.moveVoltage(12000);
  lf_motor.moveVoltage(12000);
  pros::delay(distance * 30); //distance is in inches
  lb_motor.moveVoltage(0);
  lf_motor.moveVoltage(0);
  rb_motor.moveVoltage(0);
  rf_motor.moveVoltage(0);
}
