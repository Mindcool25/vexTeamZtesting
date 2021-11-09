#include "auto.h"

void autonSelect(){
  pros::lcd::set_text(1, "Button Left: Square Dancing");
  pros::lcd::set_text(2, "Button Mid: Turn Around");
  pros::lcd::set_text(3, "Button Right: Goal Capture");

  while (true) {
    printf("Buttons Bitmap: %d\n", pros::lcd::read_buttons());
    pros::delay(20);
  }


}
