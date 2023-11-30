#pragma once
class Game{
    public:
    virtual void GameSetup();
    virtual void GameLoop();
    virtual void GameOver();
    Game();
    ~Game();
};