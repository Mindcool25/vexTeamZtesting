#include "auto.h"
#include "../include/main.h"

Motor mogoMotor(20, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);


void MOGOdown(){
  mogoMotor.moveVoltage(-11000);
  pros::delay(400);
  mogoMotor.moveVoltage(0);
}

void MOGOup(){
  mogoMotor.moveVoltage(11000);
  pros::delay(400);
  mogoMotor.moveVoltage(0);
}

void Shake(){
  mogoMotor.moveVoltage(-11000);
  pros::delay(200);
  mogoMotor.moveVoltage(11000);
  pros::delay(100);
  mogoMotor.moveVoltage(-12000);
  pros::delay(100);
  mogoMotor.moveVoltage(11000);
  pros::delay(100);
  mogoMotor.moveVoltage(-12000);
}


/*Right side auton tasks
  1. Run to Middle
  AND
  2. Achieve Win Point
  OR
  3. Do Nothing
*/

/*Left side auton tasks
  1. Run to Middle
  AND/OR
  2. Score In Team's Mobile Goal
  OR
  3. Do Nothing
*/

void autonRun(){
  if (selection == "right"){
    runRight();
  }
  else if(selection == "left"){
    runLeft();
  }
  else{
    while(pros::competition::is_autonomous()){
      pros::delay(10);
    }
  }
}

/*ON LEFT
  - Run to center
  - Grab goal with MOGO
  - Run back to start
*/
void runLeft(){
  pros::lcd::print(0, "Running Left");
  Shake();

}

/*ON RIGHT
  - Run to Win Point goal
  - Place ring in Win Point goal
  - Run to center
  - Grab center goal with
  - Run back
*/
void runRight(){
  pros::lcd::print(0, "Running Right");
  forward(-10);
  turn(65);
  MOGOdown();
  forward(-15);
  MOGOup();
  forward(5);
  turn(100);
}

void resetAll(){
	lift.tarePosition();
	tilter.tarePosition();
}
