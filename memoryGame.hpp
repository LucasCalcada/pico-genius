//#include "game.hpp"
#include "Arduino.h"
#include "constants.hpp"
#include "notePlayer.hpp"
#include "inputListener.hpp"

#pragma once

class MemoryGame{
    public:
    void GameSetup();
    void GameLoop();
    void GameOver();
    MemoryGame();
    ~MemoryGame();

    private:
    void BtnPress(uint8_t index);
    void PlaySequence();
    void ExpandSequence();

    int turn;
    int sequenceStep;
    bool canPlay;
    uint8_t sequence[256];

    inputListenerClass inputListener;
};