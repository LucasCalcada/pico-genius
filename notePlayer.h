#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef NOTE_PLAYER_H

#define NOTE_PLAYER_H

uint8_t tonePin = 0;
uint16_t badNoteSequence[] = {};
uint16_t goodNoteSequence[] = {};

void NotePlayerSetup();
void PlayNote(uint32_t,uint16_t=500);
void BadTune();
void GoodTune();

#endif