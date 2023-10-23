#include "notePlayer.h"


// Sets up buzzer pin
void NotePlayerSetup(){
    pinMode(tonePin,OUTPUT);
}

// Plays a note on the buzzer
void PlayNote(uint32_t note, uint16_t duration = 500){
    tone(tonePin, note, duration);
}

// Positive audio feedback
void GoodTune(){
    for(uint16_t note : goodNoteSequence){
        tone(tonePin,note,500);
        delay(100);
    }
}

// Negative audio feedback
void BadTune(){
    for(uint16_t note : badNoteSequence){
        tone(tonePin,note,500);
        delay(100);
    }
}