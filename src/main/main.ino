#include "gamepad.h"

class GamePad {
  public:
    void setup();
    void update(int vibro=-1);
    int joystick(unsigned int number);
    bool button(unsigned int number);
    bool button_first_tap(unsigned int number);
    byte vibration = 0;
    PS2X _ps2x; // create PS2 Controller Class
  private:
    int _error = 5; 
};

GamePad gamepad;

void GamePad::setup(){
  Serial.print("connecting with joystick");
  while (_error){ 
    _error = _ps2x.config_gamepad(PS2_clock,PS2_command,PS2_attention,PS2_data, PS2_Pressures, PS2_Rumble); 
    Serial.print(".");
  }
  Serial.println();
  Serial.println("joystick connect");
}

void GamePad::update(int vibro=-1) { 
  if (vibro>=0) vibration = vibro; 
  if(_error) return; 
  _ps2x.read_gamepad(false, vibration);
  delay(50); 
}

bool GamePad::button(unsigned int number) {
  if(_error) return 0;
  return _ps2x.Button(number);
}

bool GamePad::button_first_tap(unsigned int number) {
  if(_error) return 0;
  return _ps2x.ButtonPressed(number);
}

int GamePad::joystick(unsigned int number) {
  if(_error) return; 
  return _ps2x.Analog(number)-127;
}

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
  /*for (int i=0; i<joystick_quantity; i++) {
    if (gamepad.joystick(joystick_code[i])!=0) {
      Serial.println(joystick_name[i]);
    }
  }*/  
}
