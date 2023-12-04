#include "memoryGame.hpp"
#include "constants.hpp"
#include "notePlayer.hpp"

MemoryGame::MemoryGame(){
    turn = 1;
    sequenceStep = 0;
    canPlay = true;
}
MemoryGame::~MemoryGame(){

}
// Sets up all required pins
void MemoryGame::GameSetup(){
    Serial.println("Game setup");
    Serial.println("Led Pins:");
    for(uint8_t pin : ledPins){
        Serial.println(pin);
        pinMode(pin,OUTPUT);
    }

    inputListener = inputListenerClass();
    inputListener.InputSetup();
}

// Plays LED/Tone sequence
void MemoryGame::PlaySequence(){
 	if(!canPlay)return;
    Serial.println("Playing Sequence");
    for(int i = 0; i < turn; i++){
        int ledPin = sequence[i];	

        Serial.println(ledPin);
        Serial.println(ledPins[ledPin]);

        digitalWrite(ledPins[ledPin], HIGH);
        PlayNote(tones[ledPin]);
        delay(500);
        digitalWrite(ledPins[ledPin], LOW);
        delay(500);
    }
    canPlay = false;
    inputListener.canInput = true;
}

// Increases sequence size and assigns a new number to the end of it
void MemoryGame::ExpandSequence(){
    Serial.println("Expanding Sequence");
    uint8_t randInt = random(4);
    sequence[turn] = randInt; // Assigns new number to the end of the sequence
    sequenceStep = 0; // Resets guess sequence counter
    turn++;
    inputListener.canInput = false;
    canPlay = true;
}

// Button press behavior
void MemoryGame::BtnPress(uint8_t index){
    Serial.println("Button pressed");
    if(sequence[sequenceStep] == index){
        sequenceStep++;
        // Plays correct button sound
        PlayNote(tones[sequence[sequenceStep]]);

        delay(100);
        if(sequenceStep ==  turn - 1){
            GoodTune(); // Plays turn won sound
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
    if(canPlay){
        PlaySequence();
    }
    int8_t input = inputListener.BtnInputListener();
    if(input != -1){
        BtnPress(input);
    }
}

// Game over logic
void MemoryGame::GameOver(){
    BadTune(); // Plays gameover sound
    // Restarts game
    sequenceStep = 0;
    turn = 0;
    ExpandSequence(); 
}
