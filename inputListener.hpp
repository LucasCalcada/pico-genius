#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef LISTENER_H
#define LISTENER_H
class inputListenerClass{
    private:
        uint8_t btnPowerPin = 0;
        uint8_t btnPins[4];
        bool oldBtnVals[4];
    public:
        inputListenerClass();
        ~inputListenerClass();
        void InputSetup();
        void EnableInputIndicators();
        void DisableInputIndicators();
        void BtnInputListener(void (*callback)(uint8_t));
        bool canInput = false;
};
#endif
// extern uint8_t btnPowerPin;
// extern uint8_t btnPins[];
// extern bool canInput;
// extern bool oldBtnVals[];
// 
// void InputSetup();
// void EnableInputIndicators();
// void DisableInputIndicators();
// void BtnInputListener(void (*callback)(uint8_t));
