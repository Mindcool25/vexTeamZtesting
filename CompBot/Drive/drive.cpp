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
  distance *= 60;
  rb_motor.tarePosition();
  rf_motor.tarePosition();
  lb_motor.tarePosition();
  lf_motor.tarePosition();

  rb_motor.moveAbsolute(distance, 200);
  rf_motor.moveAbsolute(distance, 200);
  lb_motor.moveAbsolute(distance, 200);
  lf_motor.moveAbsolute(distance, 200);

  while (rb_motor.getPosition() < distance && rf_motor.getPosition() < distance && lb_motor.getPosition() < distance && lf_motor.getPosition() < distance){
    pros::delay(20);
  }

  	pros::delay(50);
}

void turn(double degrees){
  degrees *= 8.3;
  rb_motor.tarePosition();
  rf_motor.tarePosition();
  lb_motor.tarePosition();
  lf_motor.tarePosition();

  rb_motor.moveAbsolute(degrees, 200);
  rf_motor.moveAbsolute(degrees, 200);
  lb_motor.moveAbsolute(-degrees, -200);
  lf_motor.moveAbsolute(-degrees, -200);

  while (rb_motor.getPosition() < degrees && rf_motor.getPosition() < degrees && lb_motor.getPosition() < degrees && lf_motor.getPosition() < degrees){
    pros::delay(20);
  }

  pros::delay(50);
}
