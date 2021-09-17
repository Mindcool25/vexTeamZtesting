#include "main.h"
#include <iostream>

pros::Motor claw (20, pros::E_MOTOR_GEARSET_36, false);

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
	rb_mtr.tare_position();
	rf_mtr.tare_position();
	lb_mtr.tare_position();
	lf_mtr.tare_position();


	rb_mtr.move_absolute(100, 100);
	rf_mtr.move_absolute(100, 100);
	lb_mtr.move_absolute(100, 100);
	lf_mtr.move_absolute(100, 100);

	while(rb_mtr.get_position() < 100 && rb_mtr.get_position() > 70){
		pros::delay(20);
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
	std::string tempRB = "Right Back Motor Temp: "+ std::to_string(rb_mtr.get_temperature());
	std::string tempRF = "Right Front Motor Temp: "+ std::to_string(rb_mtr.get_temperature());
	std::string tempLB = "Left Back Motor Temp: "+ std::to_string(rb_mtr.get_temperature());
	std::string tempLF = "Left Front Motor Temp: "+ std::to_string(rb_mtr.get_temperature());
	std::string tempClaw = "Claw Motor Temp: "+ std::to_string(rb_mtr.get_temperature());

	pros::lcd::print(1, tempRB, pros::lcd::read_buttons());
	pros::lcd::print(1, tempRB, );
	pros::lcd::set_text(1, tempRF);
	pros::lcd::set_text(1, tempLB);
	pros::lcd::set_text(1, tempLF);
	pros::lcd::set_text(1, tempClaw);

	while (true) {

		claw.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));

		pros::delay(10);
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && run == false){
			if(run){
				arcadeDrive();
			}
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X) && run == true){
			arcadeDrive();
		}


		//starts square loop in autonomous if B is pressed
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			autonomous();
		}
	}
}
