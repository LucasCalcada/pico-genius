#include "Arduino.h"
#include "constants.hpp"
#include "memoryGame.hpp"
#include "inputListener.hpp"
#include "responseTime.hpp"

MemoryGame memoryGame;
ResponseTimeGame responseTime;
bool reactionGameMode = false;

void setup(){
    for(uint8_t pin: btnPins){
        pinMode(pin,INPUT_PULLDOWN);
    }
    pinMode(tonePin,OUTPUT);

    //Serial.begin(9600);
    //while(!Serial); //Waits for serial port 

    reactionGameMode = digitalRead(btnPins[0]);

    if(reactionGameMode){
        responseTime = ResponseTimeGame();
        responseTime.GameSetup();
    }else{
        memoryGame = MemoryGame();
        memoryGame.GameSetup();
    }
    memoryGame = MemoryGame();
    memoryGame.GameSetup();
    Serial.println("Hello World");

    Serial.println("Finished Setup");
}

void loop(){
    if(reactionGameMode){
        responseTime.GameLoop();
    }else{
        memoryGame.GameLoop();
    }
    //memoryGame.GameLoop();
    delay(100);
}