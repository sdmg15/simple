/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fulltick.h
 * Author: thecarisma
 *
 * Created on February 18, 2018, 11:15 PM
 */

#ifndef FULLTICK_H
#define FULLTICK_H

#include <png.h> 

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Adjuster.H>

#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/x.H> 
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Tooltip.H>
/** FINPUT/FTEXT(s) **/
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Multiline_Input.H>
/** FMENU/FMENUBAR(s) **/
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Sys_Menu_Bar.H>
/** FBROWSER(s) **/
#include <FL/Fl_File_Browser.H>
#include <FL/Fl_File_Chooser.H>

/* Include android Headers*/
#ifndef __ANDROID__
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#endif

#ifdef WIN32
#include <FL/x.H>
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../simple/includes/simple.h"

void test_gui(void *pointer);

SIMPLE_API void init_full_tick(SimpleState *sState) ;

#define FULLTICK_NOPARAM "No parameter is required for this block"
#define FULLTICK_MISING1PARAM "Only one parameter is required for this block "
#define FULLTICK_MISING2PARAM "Two parameters are required for this block "
#define FULLTICK_MISING3PARAM "Three parameters are required for this block "
#define FULLTICK_MISING4PARAM "Four parameters are required for this block "
#define FULLTICK_MISING5PARAM "Five parameters are required for this block "
#define FULLTICK_MISING6PARAM "Six parameters are required for this block "
#define FULLTICK_MISING7PARAM "Seven parameters are required for this block "
#define FULLTICK_WRONGPARAM "An invalid parameter has been passed to the (GUI)fulltick Module "

#ifdef __cplusplus
}
#endif

#endif /* FULLTICK_H */

