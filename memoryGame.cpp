#include "memoryGame.h"
#include "notePlayer.h"
#include "inputListener.h"

uint8_t sequence[256];
int turn = 1;
int sequenceStep = 0;
// Flags
bool canPlay = true;
// Feedback setup
int tones[] = {0,0,0,0};
uint8_t ledPins[] = {4,5,6,7};

// Sets up all required pins
void GameSetup(){
    InputSetup();
    NotePlayerSetup();
    for(uint8_t pin : ledPins){
        pinMode(pin,OUTPUT);
    }
}

// Plays LED/Tone sequence
void PlaySequence(){
 	if(!canPlay)return;
    for(int i = 0; i < turn; i++){
        int ledPin = sequence[i];	
        digitalWrite(ledPins[ledPin], HIGH);
        delay(1000);
        PlayNote(tones[ledPin]);
        digitalWrite(ledPins[ledPin], LOW);
        delay(500);
    }
    canPlay = false;
    canInput = true;
}

// Increases sequence size and assigns a new number to the end of it
void ExpandSequence(){
    uint8_t randInt = random(4);
    sequence[turn] = randInt; // Assigns new number to the end of the sequence
    sequenceStep = 0; // Resets guess sequence counter
    turn++;
    canInput = false;
    canPlay = true;
}

// Button press behavior
void BtnPress(uint8_t index){
    if(sequence[sequenceStep] == index){
        sequenceStep++;
        PlayNote(tones[sequence[sequenceStep]]); // Plays correct button sound
        delay(100);
        if(sequenceStep ==  turn - 1){
            GoodTune(); // Plays turn won sound
            ExpandSequence(); // Increases sequence size and restart
        }
        return;
    }
    GameOver();
}

// Game loop logic
void GameLoop(){
    PlaySequence();
    BtnInputListener(BtnPress);
}

// Game over logic
void GameOver(){
    BadTune(); // Plays gameover sound
    // Restarts game
    sequenceStep = 0;
    turn = 0;
    ExpandSequence(); 
}
