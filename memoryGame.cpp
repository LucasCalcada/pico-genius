#include "memoryGame.hpp"

MemoryGame::MemoryGame(){
    turn = 0;
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
    ExpandSequence();
}

// Plays LED/Tone sequence
void MemoryGame::PlaySequence(){
 	if(!canPlay)return;
    Serial.println("Playing Sequence");
    for(int i = 0; i < turn; i++){
        int ledPin = sequence[i];	
        digitalWrite(ledPins[ledPin], HIGH);
        PlayNote(notes[ledPin]);
        delay(500);
        digitalWrite(ledPins[ledPin], LOW);
        delay(500);
    }
    canPlay = false;
}

// Increases sequence size and assigns a new number to the end of it
void MemoryGame::ExpandSequence(){
    Serial.println("Expanding Sequence");
    randomSeed(analogRead(0));
    uint8_t randInt = random(4);
    sequence[turn] = randInt; // Assigns new number to the end of the sequence
    turn++;
    canPlay = true;
    DebugTurn();
}

void MemoryGame::DebugTurn(){
    Serial.println("Sequence:");
    for(int i = 0; i < turn; i++){
        Serial.print(sequence[i]);
    }
    Serial.println("\n");
}

// Game loop logic
void MemoryGame::GameLoop(){
    if(canPlay){
        PlaySequence();
    }else{
        for (int i = 0; i < turn; i++)
        {
            sequenceStep = i;
            int8_t input = BtnInputListener();
            Serial.print("Button pressed");
            Serial.print(input);
            if(sequence[sequenceStep] != input){
                GameOver();
                return;
            }else{
                digitalWrite(ledPins[input],HIGH);
                PlayNote(notes[input]);
                digitalWrite(ledPins[input],LOW);
            }

        }
        GoodTune(); // Plays turn won sound
        ExpandSequence(); // Increases sequence size and restart
    }
}

// Game over logic
void MemoryGame::GameOver(){
    Serial.println("Game over");
    BadTune(); // Plays gameover sound
    // Restarts game
    turn = 0;
    ExpandSequence(); 
}

int8_t MemoryGame::BtnInputListener(){
    //Serial.println("Reading input");
    while(true){
        for(uint8_t i = 0; i < 4; i++){
            bool press = digitalRead(btnPins[i]);
            if(!oldBtnVals[i] && press){
                oldBtnVals[i] = press;
                return i;
            }
            oldBtnVals[i] = press;
        }
        delay(50);
    }
}
