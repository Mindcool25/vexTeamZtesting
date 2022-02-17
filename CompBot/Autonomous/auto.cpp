#include "auto.h"
#include "../include/main.h"

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
  forward(-15);
  turn(60);
  moveMOGOAutoDown();
}

void resetAll(){
	lift.tarePosition();
	tilter.tarePosition();
}
