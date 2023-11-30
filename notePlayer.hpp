#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"

#endif

#ifndef NOTE_PLAYER_H

#define NOTE_PLAYER_H

extern uint8_t tonePin;
extern uint16_t badNoteSequence[];
extern uint16_t goodNoteSequence[];

void NotePlayerSetup();
void PlayNote(uint32_t);
void BadTune();
void GoodTune();

#endif