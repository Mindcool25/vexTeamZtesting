#include "main.h"

using namespace okapi;

//setup buttons on robots
okapi::ADIButton tankButton('h', false);
okapi::ADIButton arcadeButton('f', false);
okapi::ADIButton bumpButton('a', false);

//setup chassis (wow, this is a lot)
//shared_ptr (type ChassisController), name = function to build (ChassisControllerBuilder).add the motors (withMotors)({left set motors}, {right set motors}).add dimensions (withDimensions)({set gearset, set motor to wheel rotation}, {{wheel diameter, mid-tire to mid tire distance}, ticks per revolution}).build();
std::shared_ptr<okapi::ChassisController> mainChassis = okapi::ChassisControllerBuilder().withMotors({10,9},{-2,-1}).withDimensions({okapi::AbstractMotor::gearset::blue, 1}, {{4_in,14.5_in}, 300}).build();

//setup controller
okapi::Controller control(okapi::ControllerId::master);

//setup driver
std::shared_ptr<okapi::ChassisModel> drive = mainChassis->getModel();

//setup diodes on drive buttons
#define TANK_DIODE 'G'
#define ARCADE_DIODE 'E'
pros::ADIPort tankDiode(TANK_DIODE, pros::E_ADI_DIGITAL_OUT);
pros::ADIPort arcadeDiode(ARCADE_DIODE, pros::E_ADI_DIGITAL_OUT);

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);
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
void autonomous() {}

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
	//drive mode - true = tank, false = arcade
	bool driveMode;

	while (true){
		pros::delay(20);

		//test arcade vs tank buttons
		if(tankButton.isPressed()){
			driveMode = true;
		}
		else if(arcadeButton.isPressed()){
			driveMode = false;
		}

		//hi is based on tank and arcade buttons
		//arcade control vs tank control


		//true = tank; false = arcade
		if(driveMode){
			drive->tank(control.getAnalog(okapi::ControllerAnalog::leftY) * 12000, control.getAnalog(okapi::ControllerAnalog::rightY) * 12000, 0);
		}
		else{
			drive -> arcade(control.getAnalog(okapi::ControllerAnalog::rightY) * 12000, control.getAnalog(okapi::ControllerAnalog::rightX) * 12000, 0);
		}

		//front bumper button
		//on impact - move back, turn 180
		if (bumpButton.isPressed()){
			drive -> forward(-1);
			pros::delay(450);
			drive -> forward(0);
			pros::delay(500);
			drive -> rotate(6);
			pros::delay(200);
		}
	}
}
