#include "screen.h"
static  lv_res_t btn_rel_action(lv_obj_t * btn);

void screen_buttons(){
  /*MAIN SCREEN*/
  lv_obj_t * scr = lv_page_create(NULL, NULL);
  lv_scr_load(scr);

  /*TITLE*/
  lv_obj_t * label = lv_label_create(scr, NULL); /*First parameters (scr) is the parent*/
  lv_label_set_text(label, "Object usage demo");  /*Set the text*/
  lv_obj_set_x(label, 50);                        /*Set the x coordinate*/

  /*Button*/
  //type name = create function(IDK, parent);
  lv_obj_t* btn1 = lv_btn_create(lv_scr_act(), NULL);
  lv_style_set_
  //set action(object, what action, what to run);
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_rel_action);
  lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);

  /*Add label*/
  label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "PRESS TO ENLARGE");


}

static  lv_res_t btn_rel_action(lv_obj_t * btn)
{
    /*Increase the button width*/
    lv_coord_t width = lv_obj_get_width(btn);
    lv_coord_t height = lv_obj_get_height(btn);
    lv_obj_set_width(btn, width + 20);
    lv_obj_set_height(btn, height+20);

    return LV_RES_OK;
}
