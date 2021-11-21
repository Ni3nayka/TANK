#include "gamepad.h"

void setup(){
  Serial.begin(9600);
  gamepad.setup();
}

void loop(){
  gamepad.update();
  for (int i=0; i<button_quantity; i++) {
    if (gamepad.button_first_tap(button_code[i])) {
      Serial.println(button_name[i]);
    }
  }
  for (int i=0; i<joystick_quantity; i++) {
    if (gamepad.joystick(joystick_code[i])!=0) {
      Serial.print(joystick_name[i]);
      Serial.print(" ");
      Serial.println(gamepad.joystick(joystick_code[i]));
    }
  }  
  gamepad.vibration = gamepad.button(PSB_BLUE);
}
