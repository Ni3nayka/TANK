#pragma once
#include <Arduino.h>

float voltage() {
  return analogRead(A0)/40.92; 
}

int test_voltage_for_pult() {
  return map(voltage(),14.8,16.8,1,5);
}
