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
	resetAll();
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
void competition_initialize() {
	while(!pros::competition::is_autonomous()){
		if(masterController.getDigital(okapi::ControllerDigital::right)){
			selection = "right";
		}
		else if (masterController.getDigital(okapi::ControllerDigital::left)) {
			selection = "left";
		}
	}


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
	double data = 0;
	pros::Task Forward([data, &Forward](){
		while(true){
			pros::delay(20);
			forward(data);
			Forward.suspend();
		}
	});

	while(true){
		//drive
		tankDrive();
		//Move lift
		moveTilter();
		moveLift();
		//move back
		moveMOGO();

		//Y Button functions
		if(masterController.getDigital(okapi::ControllerDigital::Y)){
			/*data = 50.0;
			Forward.resume();
			*/

			/*Right side auton tasks
				1. run to center
				2. achieve win point
			*/
			data = 50;
			Forward.resume();
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

		/*DO NOT DELETE*/
		pros::delay(10);
	}


}
