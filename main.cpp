#include "Arduino.h"
#include "constants.hpp"
#include "memoryGame.hpp"
#include "inputListener.hpp"

MemoryGame game;
inputListenerClass inputListener;
void setup(){
    Serial.begin(9600);
    while(!Serial); //Wait for serial port to boot
    pinMode(tonePin,OUTPUT);
    Serial.println("Hello World");
    game = MemoryGame();
    game.GameSetup();
    // Indicates boot
    Serial.println("Finished Setup");
    inputListener = inputListenerClass();
}

void loop(){
    //Serial.println("Loop iteration");
    game.GameLoop();
    //int8_t press = inputListener.BtnInputListener();
    //Serial.print(press);
    //inputListener.ButtonDebugger();
    delay(100);
}