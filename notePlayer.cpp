#include "constants.hpp"
#include "notePlayer.hpp"

// Plays a note on the buzzer
void PlayNote(int note){
    Serial.println("Playing note ");
    Serial.print(note);
    tone(tonePin, note, toneLength);
    delay(100);
    noTone(tonePin);
    delay(100);
    Serial.print("Finished playing note");
}

// Positive audio feedback
void GoodTune(){
    for(uint16_t note : goodNoteSequence){
        tone(tonePin,note,toneLength);
        delay(100);
    }
}

// Negative audio feedback
void BadTune(){
    for(uint16_t note : badNoteSequence){
        tone(tonePin,note,toneLength);
        delay(100);
    }
}
