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

    private:
    void BtnPress(uint8_t index);
    void PlaySequence();
    void ExpandSequence();

    int turn = 1;
    int sequenceStep = 0;
    bool canPlay = true;
    int tones[5];
    uint8_t ledPins[5];
    uint8_t sequence[256];

    inputListenerClass inputListener;
    NotePlayer notePlayer;
};
// Sequence management
// extern int turn;
// extern int sequenceStep;
// Flags
// extern bool canPlay;
// Feedback setup
// extern int tones[];
// extern uint8_t ledPins[];

// void GameSetup();
// void GameLoop();
// void PlaySequence();
// void ExpandSequence();
// void BtnPress(uint8_t index);
// void GameOver();

#endif