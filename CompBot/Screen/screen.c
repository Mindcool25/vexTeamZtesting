#include "screen.h"

void selection(){
  /*MAIN SCREEN*/
  lv_obj_t * scr = lv_page_create(NULL, NULL);
  lv_scr_load(scr);

  /*TITLE*/
  lv_obj_t * label = lv_label_create(scr, NULL); /*First parameters (scr) is the parent*/
  lv_label_set_text(label, "Autonomous Selector");  /*Set the text*/
  lv_obj_set_x(label, 50);                        /*Set the x coordinate*/

  /*Button*/
  //type name = create function(parent);
  lv_obj_t* btn1 = lv_btn_create(lv_scr_act(), NULL);
  //set action(object, what action, what to run);
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_rel_action);
  lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);

  /*Add label*/
  label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "PRESS TO ENLARGE");


}

//This will litteraly do nothing for the duration of the auton
static void DoNothing(){

}

//Remove Goal on the right from the White line
/*
  Steps
1.Move to it
2.Lift it
3.Pull Back
4.Set Down
*/
static void RightTriTask(){

}

//From right side Race to Center and grab goal
/*
  Steps
1.Figure Out which Goal
2.Move to goal
3.Lift Goal
4.Move back to side

If Bumped:
Keep Goal Lifted??

*/
static void RightCenter(){

}

//From Left side, Race to Center and grab goal
/*
  Steps
1.Figure Out which Goal
2.Move to goal
3.Lift Goal
4.Move back to side

If Bumped:
Keep Goal Lifted??
*/
static void LeftCenter(){

}
