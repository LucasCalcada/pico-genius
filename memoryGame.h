#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef MEMORY_GAME_H

#define MEMORY_GAME_H
// Sequence management
uint8_t sequence[256];
int turn = 1;
int sequenceStep = 0;
// Flags
bool canPlay = true;
// Feedback setup
uint8_t tonePin = 0;
int tones[] = {0,0,0,0};
uint8_t ledPins[] = {4,5,6,7};

void GameSetup();
void GameLoop();
void PlaySequence();
void ExpandSequence();
void BtnPress(uint8_t index);
void GameOver();

#endif