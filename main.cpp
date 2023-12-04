#include "Arduino.h"
#include "memoryGame.hpp"

MemoryGame game;
void setup(){
    Serial.begin(9600);
    while(!Serial); //Wait for serial port to boot
    Serial.println("Hello World");
    game = MemoryGame();
    game.GameSetup();
    // Indicates boot
    Serial.println("Finished Setup");
}

void loop(){
    Serial.println("Loop iteration");
    game.GameLoop();
    delay(100);
}