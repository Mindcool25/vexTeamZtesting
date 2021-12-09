#include "auto.h"

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

void runLeft(){
  forward(-12);
}

void runRight(){
  //Run to Win Point Goal
  forward(-12);

  //Place ring in MG (Mobile Goal)
  //MOGOShake();

  //Grab MG
  //moveMOGOAutoDown();
  forward(-6);
  //moveMOGOAutoUp();

  //Run to center
  turn(30);
  forward(50);


}

void resetAll(){
  lift.moveVoltage(-12000);
	tilter.moveVoltage(12000);
	pros::delay(200);
	tilter.moveVoltage(0);
	pros::delay(200);
	lift.moveVoltage(0);
	lift.tarePosition();
	tilter.tarePosition();
}
