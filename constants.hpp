#include "Arduino.h"

#pragma once
const uint8_t ledPins[] = {4,5,6,7};

// ---------- Note Player ----------
const float noteC4 = 261.63;
const float noteD4 = 293.66;
const float noteE4 = 329.63;
const float noteF4 = 349.23;
const float noteG4 = 392.00;
const float noteA4 = 440.00;
const float noteB4 = 493.88;

const float tones[] = {noteC4,noteE4,noteG4,noteB4};
const uint8_t tonePin = 15;
// Note length in ms
const int toneLength = 500;
// Note sequence feedback
const int badNoteSequence[] = {};
const int goodNoteSequence[] = {};

// ---------- Input Listener --------
const uint8_t btnPowerPin = 0;
const uint8_t btnPins[] = {24,25,26,27};
