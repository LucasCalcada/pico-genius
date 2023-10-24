#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef INPUT_LISTENER

#define INPUT_LISTENER

extern uint8_t btnPowerPin;
extern uint8_t btnPins[];
extern bool canInput;
extern bool oldBtnVals[];

void InputSetup();
void EnableInputIndicators();
void DisableInputIndicators();
void BtnInputListener(void (*callback)(uint8_t));

#endif