#include"Minesweeper.hpp"

Minesweeper::Minesweeper() {
    mWindow.create(sf::VideoMode(800, 600), "Minesweeper");
    Scene::setWindow(mWindow);
}

void Minesweeper::run(){
    mState= GameState::Game;
    while(mWindow.isOpen()){
        switch(mState){
            case Game:
                mState= mGame.run();
                break;
            case Menu:
                mState= mMenu.run();
                break;
            case Exit:
                mWindow.close();
                break;
            case Continue:
                break;
        }
    }
}
