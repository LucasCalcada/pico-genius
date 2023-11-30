#ifndef ARDUINO_H

#define ARDUINO_H
#include "Arduino.h"
#endif

#pragma once

class NotePlayer{
    private:
    // Buzzer Pin
    uint8_t tonePin = 0;
    // Note length in ms
    uint8_t toneLength = 500;
    // Note sequence feedback
    static uint16_t badNoteSequence[];
    static uint16_t goodNoteSequence[];
    public:
    NotePlayer();
    ~NotePlayer();
    void Setup();
    void PlayNote(uint32_t);
    void BadTune();
    void GoodTune();
};