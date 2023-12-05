#include "Arduino.h"
#include "constants.hpp"

#pragma once
class inputListenerClass{
    private:
        bool oldBtnVals[4];
    public:
        inputListenerClass();
        ~inputListenerClass();
        void ButtonDebugger();
        bool IsAnyButtonPressed();
        int8_t BtnInputListener();
        void Setup();
};