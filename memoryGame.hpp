#include "game.hpp"
#include "notePlayer.hpp"
#include "inputListener.hpp"
#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef MEMORY_GAME_H

#define MEMORY_GAME_H

class MemoryGame:public Game{
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
    int tones[5];
    uint8_t ledPins[4];
    uint8_t sequence[256];

    inputListenerClass inputListener;
    NotePlayer notePlayer;
};

#endif