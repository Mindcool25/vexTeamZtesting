#include "main.h"
#include <iostream>



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
	square();






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
	std::string tempRB = "Right Back Motor Temp: " + std::to_string(rb_mtr.getTemperature());
	std::string tempRF = "Right Front Motor Temp: " + std::to_string(rf_mtr.getTemperature());
	std::string tempLB = "Left Back Motor Temp: " + std::to_string(lb_mtr.getTemperature());
	std::string tempLF = "Left Front Motor Temp: " + std::to_string(lf_mtr.getTemperature());

	pros::lcd::set_text(1, tempRB);
	pros::lcd::set_text(2, tempRF);
	pros::lcd::set_text(3, tempLB);
	pros::lcd::set_text(4, tempLF);

	while (true) {
		tempRB = "Right Back Motor Temp: " + std::to_string(rb_mtr.getTemperature());
		tempRF = "Right Front Motor Temp: " + std::to_string(rf_mtr.getTemperature());
		tempLB = "Left Back Motor Temp: " + std::to_string(lb_mtr.getTemperature());
		tempLF = "Left Front Motor Temp: " + std::to_string(lf_mtr.getTemperature());

		pros::lcd::set_text(1, tempRB);
		pros::lcd::set_text(2, tempRF);
		pros::lcd::set_text(3, tempLB);
		pros::lcd::set_text(4, tempLF);


		drive();

		if(master.getDigital(okapi::ControllerDigital::Y)){
			autonomous();
		}
	}
}
