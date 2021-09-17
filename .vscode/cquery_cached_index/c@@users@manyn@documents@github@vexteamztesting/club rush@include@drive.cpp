#include "main.h"

#define RIGHT_FRONT_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 1
#define LEFT_FRONT_MOTOR_PORT 9
#define LEFT_BACK_MOTOR_PORT 10

bool run;

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);


//tank drive control
void tankDrvie(bool runPass){
  run = runPass;
  while(run){
    pros::delay(10);

  }
}

//arcade drive control - Runs everytime it is called
//should run if Arcade Drive is pressed
void arcadeDrive(){
  pros::delay(10);
  int power = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
	int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	rb_mtr = power - turn;
	rf_mtr = power - turn;

	lf_mtr = power + turn;

	lb_mtr = power + turn;
}
