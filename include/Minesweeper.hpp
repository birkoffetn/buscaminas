#ifndef __MINESWEEPER__HPP__
#define __MINESWEEPER__HPP__

#include"GameScene.hpp"
#include"MenuScene.hpp"

#include<SFML/Graphics.hpp>

class Minesweeper{
public:
    Minesweeper();
    void run();
private:
    sf::RenderWindow mWindow;
    GameScene mGame;
    MenuScene mMenu;
    GameState mState;
};

#endif
