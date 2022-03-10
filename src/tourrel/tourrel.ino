#include "SoftwareSerial.h"

SoftwareSerial bluetooth(10, 11); // RX, TX

bool mode = 1; // 1 - bluetooth, 0 - serial

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char t = Serial.read();
    if      (t=='m') mode = 0;
    else if (t=='M') mode = 1;
    else robot_control(t);
  }
  
  if (bluetooth.available()) {
    char t = bluetooth.read();
    robot_control(t);
  }
}

void robot_control(char c) {
  if (c=='w');
  else;
}
