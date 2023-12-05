#include "notePlayer.hpp"

// Plays a tone on the pico
void picoTone(float note, unsigned long int length){
    unsigned long StartTime = millis();
    float interval = (1000.0 * 1000.0) / (note * 2);
    Serial.println(interval);
    while(millis() - StartTime < length){
        digitalWrite(tonePin,HIGH);
        delayMicroseconds((int)interval);
        digitalWrite(tonePin,LOW);
        delayMicroseconds((int)interval);
    }
}
// Plays a note on the buzzer
void PlayNote(float note){
    Serial.println("Playing note ");
    Serial.print(note);
    picoTone(note, 500);
    Serial.println("Finished playing note");
    delay(100);
}

// Positive audio feedback
void GoodTune(){
    for(int note : goodNoteSequence){
        picoTone(note,500);
        delay(100);
    }
}

// Negative audio feedback
void BadTune(){
    for(int note : badNoteSequence){
        picoTone(note,500);
        delay(100);
    }
}