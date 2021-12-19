#pragma once
#include <Arduino.h>

float voltage() {
  return analogRead(A0)/40.92; 
}
