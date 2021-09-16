#include "main.h"
#include "pros/setup.hpp"
#include <iostream>

//create drive chassis through okapi
std::shared_ptr<ChassisController> drive = ChassisControllerBuilder().withMotors(RIGHT_BACK_MOTOR_PORT, -LEFT_BACK_MOTOR_PORT, RIGHT_FRONT_MOTOR_PORT, -LEFT_FRONT_MOTOR_PORT).build();


//Create controller
Controller controller;

//create button object to check for autonomous
ControllerButton autoPressed(ControllerDigital::B);

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
	for (int i = 0; i < 4; i++){
		drive -> moveDistance(12_in);
		drive -> turnAngle(90_deg);
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
	pros::Motor lf_mtr(LEFT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor lb_mtr(LEFT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor rf_mtr(RIGHT_FRONT_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);
	pros::Motor rb_mtr(RIGHT_BACK_MOTOR_PORT, pros::E_MOTOR_GEARSET_06, true);

	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {
		pros::delay(10);

		drive->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));

		//starts square loop in autonomous if B is pressed
		if (autoPressed.isPressed()){
			autonomous();
		}


	}
}
