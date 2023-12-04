#include "Arduino.h"

#pragma once
const uint8_t ledPins[] = {4,5,6,7};

// ---------- Note Player ----------
const int tones[] = {523,587,659,698};
const uint8_t tonePin = 0;
// Note length in ms
const int toneLength = 500;
// Note sequence feedback
const int badNoteSequence[] = {};
const int goodNoteSequence[] = {};

// ---------- Input Listener --------
const uint8_t btnPowerPin = 0;
const uint8_t btnPins[] = {24,25,26,27};
