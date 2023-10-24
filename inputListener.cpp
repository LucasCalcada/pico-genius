#include "inputListener.h"

// Input pin setup
void InputSetup(){
    for(uint8_t pin : btnPins){
        pinMode(pin,INPUT);
    }
}

// Enable button power
void EnableInputIndicators(){
    digitalWrite(btnPowerPin,HIGH);
}

// Disable button power
void DisableInputIndicators(){
    digitalWrite(btnPowerPin,LOW);
}

// Read button input
void BtnInputListener(void (*callback)(uint8_t)){
    if(!canInput) return;
    for(uint8_t i = 0; i < 4; i++){
        bool press = digitalRead(btnPins[i]);
        if(!oldBtnVals[i] && press){
            callback(i);
        }
        oldBtnVals[i] = press;
    }
}