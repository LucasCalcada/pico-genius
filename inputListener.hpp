#include "Arduino.h"
#include "constants.hpp"

#pragma once
class inputListenerClass{
    private:
        bool oldBtnVals[4];
    public:
        inputListenerClass();
        ~inputListenerClass();
        void InputSetup();
        void EnableInputIndicators();
        void ButtonDebugger();
        void DisableInputIndicators();
        int8_t BtnInputListener();
};