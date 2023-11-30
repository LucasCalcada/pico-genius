#include "Arduino.h"
#include "game.hpp"
#include "memoryGame.h"

MemoryGame game;
void setup(){
    game = MemoryGame();
    game.GameSetup();
}

void loop(){
    game.GameLoop();
}