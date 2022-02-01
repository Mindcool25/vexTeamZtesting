#include "screen.h"

void on_center_button(){
  selection = "None";
}
void on_right_button(){
  selection = "right";
}
void on_left_button(){
  selection = "left";
}
void setup_screen(){
  pros::lcd::initialize();
  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_right_button);
}
