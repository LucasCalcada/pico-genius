#include "memoryGame.h"
#include "game.hpp"

// Sets up all required pins
void MemoryGame::GameSetup(){
    Serial.begin(9600);

    inputListener = inputListenerClass();
    inputListener.InputSetup();

    notePlayer = NotePlayer();
    notePlayer.Setup();

    for(uint8_t pin : ledPins){
        pinMode(pin,OUTPUT);
    }
}

// Plays LED/Tone sequence
void MemoryGame::PlaySequence(){
 	if(!canPlay)return;
    for(int i = 0; i < turn; i++){
        int ledPin = sequence[i];	
        digitalWrite(ledPins[ledPin], HIGH);
        notePlayer.PlayNote(tones[ledPin]);
        delay(500);
        digitalWrite(ledPins[ledPin], LOW);
        delay(500);
    }
    canPlay = false;
    inputListener.canInput = true;
}

// Increases sequence size and assigns a new number to the end of it
void MemoryGame::ExpandSequence(){
    uint8_t randInt = random(4);
    sequence[turn] = randInt; // Assigns new number to the end of the sequence
    sequenceStep = 0; // Resets guess sequence counter
    turn++;
    inputListener.canInput = false;
    canPlay = true;
}

// Button press behavior
void MemoryGame::BtnPress(uint8_t index){
    if(sequence[sequenceStep] == index){
        sequenceStep++;
        // Plays correct button sound
        notePlayer.PlayNote(tones[sequence[sequenceStep]]);
        delay(100);
        if(sequenceStep ==  turn - 1){
            notePlayer.GoodTune(); // Plays turn won sound
            ExpandSequence(); // Increases sequence size and restart
        }
        return;
    }
    else{
        GameOver();
    }
}

// Game loop logic
void MemoryGame::GameLoop(){
    PlaySequence();
    int8_t input = inputListener.BtnInputListener();
    if(input != -1){
        BtnPress(input);
    }
}

// Game over logic
void MemoryGame::GameOver(){
    notePlayer.BadTune(); // Plays gameover sound
    // Restarts game
    sequenceStep = 0;
    turn = 0;
    ExpandSequence(); 
}
