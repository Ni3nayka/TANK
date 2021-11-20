#pragma once
#include <Arduino.h>
#include "PS2X_lib.h"  //for v1.6

const uint8_t  PS2_clock          = A3;    // CLK
const uint8_t  PS2_data           = A1;    // DAT (DTA)
const uint8_t  PS2_command        = A2;    // CMD
const uint8_t  PS2_attention      = A4;    // ATT

const bool     PS2_Pressures      = true;  // установка флага на чтение аналоговых значений с геймпада
const bool     PS2_Rumble         = true;  

const unsigned int button_quantity = 16;
const unsigned int button_code[button_quantity] = {PSB_START,PSB_SELECT,PSB_PAD_UP,PSB_PAD_RIGHT,PSB_PAD_LEFT,PSB_PAD_DOWN,PSB_L2,PSB_R2,PSB_GREEN,PSB_RED,PSB_PINK,PSB_BLUE,PSB_L1,PSB_R1,PSB_L3,PSB_R3};
const String button_name[button_quantity] = {"PSB_START","PSB_SELECT","PSB_PAD_UP","PSB_PAD_RIGHT","PSB_PAD_LEFT","PSB_PAD_DOWN","PSB_L2","PSB_R2","PSB_GREEN","PSB_RED","PSB_PINK","PSB_BLUE","PSB_L1","PSB_R1","PSB_L3","PSB_R3"};

const unsigned int joystick_quantity = 4;
const unsigned int joystick_code[joystick_quantity] = {PSS_LY,PSS_LX ,PSS_RY,PSS_RX};
const String joystick_name[joystick_quantity] = {"PSS_LY","PSS_LX","PSS_RY","PSS_RX"};

/*
кнопки:

PSB_START
PSB_SELECT
              
PSB_PAD_UP
PSB_PAD_RIGHT
PSB_PAD_LEFT
PSB_PAD_DOWN

PSB_GREEN  // треугольник
PSB_RED    // куруг
PSB_PINK   // квадрат
PSB_BLUE   // крест

PSB_L1
PSB_R1
PSB_L2
PSB_R2

джойстик:

PSB_L3
PSB_R3
PSS_LY  
PSS_LX 
PSS_RY
PSS_RX
*/
