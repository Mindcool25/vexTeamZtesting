#include "main.h"
#include <iostream>

#define RIGHT_FRONT_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 1
#define LEFT_FRONT_MOTOR_PORT 9
#define LEFT_BACK_MOTOR_PORT 10



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false);
	pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_18, false);

	while (true){
		lf_mtr = 127;
		rf_mtr = 127;
	}

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor lb_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor rf_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor rb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);

	while (true) {
		pros::delay(10);
		pros::lcd::set_text(1, "BYE!");
		//arcade controls
		int  vert = master.get_analog(ANALOG_LEFT_Y);
		int horiz = master.get_analog(ANALOG_RIGHT_X);

		int left = vert + horiz;
		int right = vert - horiz;
		std::cout << "Right: " << right << std::endl;
		master.print(0, 0, "Left: %d", left);
		master.print(0, 0, "Right: %d", right);

		lf_mtr.move(left);
		lb_mtr.move(left);

		rb_mtr.move(right);
		rb_mtr.move(right);


		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
			rb_mtr = 127;
			rf_mtr = 127;
			lf_mtr = 127;
			rf_mtr = 127;
		}

		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			rb_mtr = -127;
			rf_mtr = -127;
			lf_mtr = -127;
			rf_mtr = -127;
		}
		else{
			rb_mtr = 0;
			rf_mtr = 0;
			lf_mtr = 0;
			rf_mtr = 0;
		}







	}
}
