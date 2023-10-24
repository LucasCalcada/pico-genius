#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef MEMORY_GAME_H

#define MEMORY_GAME_H
// Sequence management
extern int turn;
extern int sequenceStep;
// Flags
extern bool canPlay;
// Feedback setup
extern int tones[];
extern uint8_t ledPins[];

void GameSetup();
void GameLoop();
void PlaySequence();
void ExpandSequence();
void BtnPress(uint8_t index);
void GameOver();

#endif