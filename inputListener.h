#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef INPUT_LISTENER

#define INPUT_LISTENER
uint8_t btnPowerPin = 9;
uint8_t btnPins[] = {10,11,12,13};

bool canInput = false;
bool oldBtnVals[] = {false,false,false,false};

void InputSetup();
void EnableInputIndicators();
void DisableInputIndicators();
void BtnInputListener(void (*callback)(uint8_t));

#endif