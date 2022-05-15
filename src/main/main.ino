#include "gamepad.h"
#include "motor.h"
#include "voltmetr.h"

#include <Servo.h>
Servo gnu_tank;
Servo povorot_bashni_gorizontal;
Servo povorot_bashni_vertical;

int servo_val = 90;
int servo_gorizontal_val = 90;
int servo_vertical_val = 90;

void setup(){
  Serial.begin(9600);
  gamepad.setup();
  gnu_tank.attach(9);
  povorot_bashni_gorizontal.attach(10);
  povorot_bashni_vertical.attach(A5);
}

void loop(){
  gamepad.update();
  motor(LEFT,  gamepad.joystick(PSS_LY));
  motor(RIGHT, gamepad.joystick(PSS_RY));

  if (gamepad.button(PSB_BLUE)) servo_val++;
  if (gamepad.button(PSB_GREEN)) servo_val--;
  
  if (gamepad.button(PSB_PAD_LEFT)) servo_gorizontal_val++;
  if (gamepad.button(PSB_PAD_RIGHT)) servo_gorizontal_val--;
  
  if (gamepad.button(PSB_PAD_UP)) servo_vertical_val++;
  if (gamepad.button(PSB_PAD_DOWN)) servo_vertical_val--;
  
  gnu_tank.write(servo_val);
  povorot_bashni_gorizontal.write(servo_gorizontal_val);
  povorot_bashni_vertical.write(servo_vertical_val);
  
  gamepad.vibration = gamepad.button(PSB_RED);
}
