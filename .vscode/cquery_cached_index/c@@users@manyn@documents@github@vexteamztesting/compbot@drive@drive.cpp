#include "../include/main.h"
#include "drive.h"

okapi::Controller masterController(ControllerId::master);

//Chassis controller  stuff
//ignore error - it compiles fine
std::shared_ptr<okapi::ChassisController> chassisModel = okapi::ChassisControllerBuilder().withMotors({LEFT_MOTOR_BACK, -LEFT_MOTOR_FRONT}, {-RIGHT_MOTOR_BACK, RIGHT_MOTOR_FRONT}).withDimensions({okapi::AbstractMotor::gearset::blue, 1}, {{4_in, 14.5_in}, 900}).build();
std::shared_ptr<okapi::ChassisModel> driveTrain = chassisModel->getModel();

void tankDrive(){
  leftInput = masterController.getAnalog(ControllerAnalog::leftY)*12000;
  rightInput = masterController.getAnalog(ControllerAnalog::rightY)*12000;
  std::cout << masterController.getAnalog(ControllerAnalog::rightY) << std::endl;
  driveTrain->tank(rightInput, leftInput, 0);
  //yes
}

void forward(double distance){
  driveTrain -> resetSensors();
  while(driveTrain->getSensorVals()[0] < distance){
     //driveTrain->forward(127);
     std::cout << driveTrain->getSensorVals()[0] << std::endl;
  }
}
