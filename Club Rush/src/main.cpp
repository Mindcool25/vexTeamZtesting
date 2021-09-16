#include "main.h"
#include "setup.h"
#include <iostream>


#define RIGHT_FRONT_MOTOR_PORT 2
#define RIGHT_BACK_MOTOR_PORT 1
#define LEFT_FRONT_MOTOR_PORT 9
#define LEFT_BACK_MOTOR_PORT 10


pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);

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
	pros::lcd::set_text(1, "Hello World!");

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
	rb_mtr.move_relative(100,120);
	rf_mtr.move_relative(100,120);
	lb_mtr.move_relative(100,120);
	lf_mtr.move_relative(100,120);
	while (!((rb_mtr.get_position() < 105) && (rb_mtr.get_position() > 95))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
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

	while (true) {
		pros::delay(10);

		int power = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		rb_mtr = power - turn;
		rf_mtr = power - turn;

		lf_mtr = power + turn;

		lb_mtr = power + turn;
		//drive->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));

		//starts square loop in autonomous if B is pressed
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			autonomous();
		}
	}
}
