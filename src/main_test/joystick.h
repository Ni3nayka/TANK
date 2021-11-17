#include "PS2X_lib.h"  //for v1.6

uint8_t  PS2_clock          = A0;   // CLK
uint8_t  PS2_data           = A1;   // DAT
uint8_t  PS2_command        = A2;   // CMD
uint8_t  PS2_attention      = A3;
bool     PS2_Pressures      = true; // установка флага на чтение аналоговых значений с геймпада
bool     PS2_Rumble         = true;

int error = 0; 
byte type = 0;
byte vibrate = 0;

PS2X ps2x; // create PS2 Controller Class

void setup_joystick() {
  error = ps2x.config_gamepad(PS2_clock, PS2_command, PS2_attention, PS2_data, PS2_Pressures, PS2_Rumble);        // Инициируем работу геймпада

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }
}
