#include "notePlayer.hpp"

// Plays a tone on the pico
void picoTone(float note, unsigned long int length){
    unsigned long StartTime = millis();
    float interval = (1000.0 * 1000.0) / (note * 2.0);
    while(millis() - StartTime < length){
        digitalWrite(tonePin,HIGH);
        delayMicroseconds((int)interval);
        digitalWrite(tonePin,LOW);
        delayMicroseconds((int)interval);
    }
}
// Plays a note on the buzzer
void PlayNote(float note){
    picoTone(note, 500);
    delay(100);
}

// Positive audio feedback
void GoodTune(){
    Serial.println("Good Tune");
    for(float note : goodNoteSequence){
        picoTone(note,300);
        delay(50);
    }
}

// Negative audio feedback
void BadTune(){
    for(uint8_t pin: ledPins){
        digitalWrite(pin,HIGH);
    }
    Serial.print("Bad Tune");
        for(float note : badNoteSequence){
        picoTone(note,200);
        delay(50);
    }
    for(uint8_t pin: ledPins){
    
        digitalWrite(pin,LOW);
    }
}