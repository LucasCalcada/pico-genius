#include "memoryGame.h"
#include "notePlayer.h"
#include "inputListener.h"

// Sets up all required pins
void GameSetup(){
    InputSetup();
    NotePlayerSetup();
    for(uint8_t pin : ledPins){
        pinMode(pin,OUTPUT);
    }
}

// Plays LED sequence
void PlaySequence(){
 	if(!canPlay)return;
    for(int i = 0; i < turn; i++){
        int ledPin = sequence[i];	
        digitalWrite(ledPins[ledPin], HIGH);
        delay(1000);
        digitalWrite(ledPins[ledPin], LOW);
        delay(500);
    }
    canPlay = false;
    canInput = true;
}

// Increases sequence size and assigns a new number to the end of it
void ExpandSequence(){
    uint8_t randInt = random(4);
    sequence[turn] = randInt;
    sequenceStep = 0;
    turn++;
    canInput = false;
    canPlay = true;
}

// Button press behavior
void BtnPress(uint8_t index){
    if(sequence[sequenceStep] == index){
        sequenceStep++;
        if(sequenceStep ==  turn - 1) ExpandSequence();
        return;
    }
    GameOver();
}

void GameLoop(){
    PlaySequence();
    BtnInputListener(BtnPress);
}

uint32_t gameOverTune[] = {};
void GameOver(){
    sequenceStep = 0;
    for(int t : gameOverTune){
        tone(tonePin, t, 500);
    }
    ExpandSequence();

    // limpar sequencia
    // Som fim de jogo
    // Recomeçar
}
