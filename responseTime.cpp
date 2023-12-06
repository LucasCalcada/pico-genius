#include "responseTime.hpp"
void ResponseTimeGame::GameSetup(){
    Serial.print("Game Setup");

    inputListener = inputListenerClass();
    inputListener.Setup();

    for(uint8_t pin : ledPins){
        pinMode(pin,OUTPUT);
    }
}

void ResponseTimeGame::GameLoop(){
    Serial.println("Game Loop");
    ChooseBtn();
    int8_t pressedBtn = inputListener.BtnInputListener();
    if(pressedBtn != currentBtn){
        BadTune();
    }
    else{
        GoodTune();
    }
}

void ResponseTimeGame::ChooseBtn(){
    for(uint8_t pin:ledPins){
        digitalWrite(ledPins[pin],LOW);
    }
    Serial.println("Choosing btn");
    // Chooses a button to press
    randomSeed(analogRead(0));
    uint8_t index = random(4);
    currentBtn = index;

    // Chooses a random time to press the button
    unsigned long int randomLength = random(0,5000);
    unsigned long int startTime = millis();
    Serial.println(randomLength);
    Serial.println("Btn chosen");
    // Looses if button is pressed before showing up
    while(millis() - startTime < randomLength){
        if(inputListener.IsAnyButtonPressed()){
            BadTune();
            return;
        }
    }
    Serial.println("Showing btn");
    digitalWrite(ledPins[index],HIGH);
    picoTone(notes[index],100);
    digitalWrite(ledPins[index],LOW);
}
