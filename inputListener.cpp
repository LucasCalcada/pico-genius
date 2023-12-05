#include "inputListener.hpp"

// Constructor Method
inputListenerClass::inputListenerClass(){
    
}
// Destructor Method
inputListenerClass::~inputListenerClass(){

}
// Input pin setup
void inputListenerClass::InputSetup(){
    Serial.println("Input listener setup");
    for(uint8_t pin : btnPins){
        pinMode(pin,INPUT_PULLDOWN);
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
    //Serial.println("Reading input");
    while(true){
        for(uint8_t i = 0; i < 4; i++){
            bool press = digitalRead(btnPins[i]);
            if(!oldBtnVals[i] && press){
                oldBtnVals[i] = press;
                return i;
            }
            oldBtnVals[i] = press;
        }
        delay(50);
    }
}

void inputListenerClass::ButtonDebugger(){
    Serial.println("");
    for(uint8_t i = 0; i < 4; i++){
            bool press = digitalRead(btnPins[i]);
            if(press){
                Serial.print(1);
            }
            else{
                Serial.print(0);
            }
        }
}