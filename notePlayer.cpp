#include "notePlayer.hpp"
#include "pwm.h"


// Same as Arduino tone() but works on the pico
void picoTone(int note, unsigned long int length){
    unsigned long StartTime = millis();
    while(millis() - StartTime < length){
        float interval = 1000 / note;
        digitalWrite(tonePin,HIGH);
        delay(interval/2);
        digitalWrite(tonePin,LOW);
        delay(interval/2);
    }
}
// Plays a note on the buzzer
void PlayNote(int note){
    Serial.println("Playing note ");
    Serial.print(note);
    picoTone(tonePin, note, toneLength);
    Serial.println("Finished playing note");
    delay(100);
}

// Positive audio feedback
void GoodTune(){
    for(int note : goodNoteSequence){
        picoTone(tonePin,note,toneLength);
        delay(100);
    }
}

// Negative audio feedback
void BadTune(){
    for(int note : badNoteSequence){
        picoTone(tonePin,note,toneLength);
        delay(100);
    }
}
