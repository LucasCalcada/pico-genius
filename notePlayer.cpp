#include "notePlayer.hpp"

uint16_t NotePlayer::goodNoteSequence[] = {0,0,0,0};
uint16_t NotePlayer::badNoteSequence[] = {0,0,0,0};

NotePlayer::NotePlayer(){

}
NotePlayer::~NotePlayer(){

}
// Sets up buzzer pin
void NotePlayer::Setup(){
    pinMode(tonePin,OUTPUT);
    Serial.println("Note Player setup");
}

// Plays a note on the buzzer
void NotePlayer::PlayNote(uint32_t note){
    tone(tonePin, note, toneLength);
}

// Positive audio feedback
void NotePlayer::GoodTune(){
    for(uint16_t note : goodNoteSequence){
        tone(tonePin,note,toneLength);
        delay(100);
    }
}

// Negative audio feedback
void NotePlayer::BadTune(){
    for(uint16_t note : badNoteSequence){
        tone(tonePin,note,toneLength);
        delay(100);
    }
}
