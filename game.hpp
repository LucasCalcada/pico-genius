#ifndef ARDUINO_H
#define ARDUINO_H
#include "Arduino.h"
#endif

#pragma once
class Game{
    protected:
    static int tones[];
    static uint8_t ledPins[];
    public:
    virtual void GameSetup();
    virtual void GameLoop();
    virtual void GameOver();
    Game();
    ~Game();
};