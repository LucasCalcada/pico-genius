#include "inputListener.hpp"

// Constructor Method
inputListenerClass::inputListenerClass(){
    btnPins[0] = 0;
    btnPins[1] = 0;
    btnPins[2] = 0;
    btnPins[3] = 0;
}
// Destructor Method
inputListenerClass::~inputListenerClass(){

}
// Input pin setup
void inputListenerClass::InputSetup(){
    for(uint8_t pin : inputListenerClass::btnPins){
        pinMode(pin,INPUT);
    }
}

// Enable button power
void inputListenerClass::EnableInputIndicators(){
    digitalWrite(btnPowerPin,HIGH);
}

// Disable button power
void inputListenerClass::DisableInputIndicators(){
    digitalWrite(btnPowerPin,LOW);
}

// Read button input
void inputListenerClass::BtnInputListener(void (*callback)(uint8_t)){
    if(!canInput) return;
    for(uint8_t i = 0; i < 4; i++){
        bool press = digitalRead(btnPins[i]);
        //Serial.print(i);
        
        if(!oldBtnVals[i] && press){
            callback(i);
            Serial.print(i);
        }
        oldBtnVals[i] = press;
    }
}