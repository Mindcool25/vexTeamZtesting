#include "../include/main.h"
#include "../include/globals.h"

void on_center_button(){
	selection = "None";
}
void on_right_button(){
	selection = "Right";
}
void on_left_button(){
	selection = "Left";
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);
	//screen_buttons();
	resetAll();
	disabled();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	selection = "Right";
	while (pros::competition::is_disabled()){
		if(masterController.getDigital(okapi::ControllerDigital::Y)){
			selection = "Left";
			std::cout << "Left" << std::endl;
		}
		else if(masterController.getDigital(okapi::ControllerDigital::A)){
			selection = "Right";
			std::cout << "Right" << std::endl;
		}
		std::cout << selection << std::endl;
	}

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

}

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
	autonRun();
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
	//Setup motors
	setupDriveMotors(0);
	setupLift();

	while(true){
		//drive
		tankDrive();
		//Move lift
		moveTilter();
		moveLift();
		//move back
		moveMOGO();

		/*DO NOT DELETE*/
		pros::delay(10);
	}


}
