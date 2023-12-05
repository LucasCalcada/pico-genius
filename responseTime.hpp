#include "Arduino.h"
#include "constants.hpp"
#include "notePlayer.hpp"
#include "inputListener.hpp"

#pragma once

class ResponseTimeGame{
    public:
    void GameSetup();
    void GameLoop();
    void GameOver();
    private:
    void ChooseBtn();
    inputListenerClass inputListener;
    uint8_t currentBtn = 0;
    bool canPress = false;
};
