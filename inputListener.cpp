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
int8_t inputListenerClass::BtnInputListener(){
    if(!canInput) return -1;
    for(uint8_t i = 0; i < 4; i++){
        bool press = digitalRead(btnPins[i]);
        
        if(!oldBtnVals[i] && press){
            oldBtnVals[i] = press;
            return i;
        }
        oldBtnVals[i] = press;
    }
    return -1;
}