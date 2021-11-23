#include "../include/main.h"
#include "../include/globals.h"


/*[({

})]*/
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//pros::lcd::initialize();
	//screen_buttons();
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
	setupDriveMotors(0);
	while(true){
		tankDrive();
		moveLift();
		moveMOGO();
		if(masterController.getDigital(okapi::ControllerDigital::up)){
			moveMOGOAutoUp();
		}
		if(masterController.getDigital(okapi::ControllerDigital::down)){
			moveMOGOAutoDown();
		}
		if(masterController.getDigital(okapi::ControllerDigital::Y)){
			auto glambda = [](double act) {forward(50);};
			//glambda(50);
			int* fifty;
			*fifty = 50;
			pros::Task forward50(&glambda, fifty, "Forward50");
			//pros::Task autoLifter(moveLiftAuto, 2000.0, "LiftUp");
			// forward(50);
			// moveLiftAuto(2000);
			// pros::delay(10);
			// forward(-24);
			// turn(-90);
			// forward(-10);
			// MOGOShake();
			// moveMOGOAutoDown();
			// forward(-10);
			// moveMOGOAutoUp();
			// forward(21);
			// turn(90);
			// forward(-24);
		}
		if(masterController.getDigital(okapi::ControllerDigital::X)){
			//pros::Task forward50(my_task_fn);
			pros::Task Shake(MOGOShake);
			pros::delay(500);

		}


		pros::delay(10);
	}


}
