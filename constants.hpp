#include "Arduino.h"
#pragma once

int tones[] = {523,587,659,698};
uint8_t ledPins[] = {4,5,6,7};

// Note Player
uint8_t tonePin = 0;
// Note length in ms
int toneLength = 500;
// Note sequence feedback
int badNoteSequence[] = {};
int goodNoteSequence[] = {};
