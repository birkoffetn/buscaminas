#ifndef __GAME__HPP__
#define __GAME__HPP__

#include"GameField.hpp"
#include"Board.hpp"

class Game{
public:
    Game();
    void init();
    int run();
protected:
    void readInput();
    void updateLogic(float dt);
    void draw();
private:
    sf::RenderWindow mWindow;
    sf::Clock mClock;
    GameField mField;
    Board mBoard;
};

#endif