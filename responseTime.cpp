#include "responseTime.hpp"

void ResponseTimeGame::GameSetup(){
    inputListener = inputListenerClass();
    inputListener.Setup();
}

void ResponseTimeGame::GameLoop(){
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
    // Chooses a button to press
    randomSeed(analogRead(0));
    uint8_t index = random(4);

    // Chooses a random time to press the button
    unsigned long int randomLength = random(0,5000);
    unsigned long int startTime = millis();

    // Looses if button is pressed before showing up
    while(millis() - startTime < randomLength){
        if(inputListener.IsAnyButtonPressed()){
            BadTune();
            return;
        }
    }

    digitalWrite(ledPins[index],HIGH);
    picoTone(notes[index],100);
    digitalWrite(ledPins[index],LOW);
}