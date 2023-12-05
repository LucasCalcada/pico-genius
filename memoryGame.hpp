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
    void PlaySequence();
    void ExpandSequence();
    void DebugTurn();

    int turn;
    int sequenceStep;
    bool canPlay;
    int8_t sequence[256];

    inputListenerClass inputListener;
};