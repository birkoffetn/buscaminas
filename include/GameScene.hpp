#ifndef __GAME_SCENE__HPP__
#define __GAME_SCENE__HPP__

#include"Scene.hpp"
#include"Field.hpp"
#include"Board.hpp"
#include"constants.hpp"

class GameScene: public Scene{
public:
    void init();
protected:
    int readEvent(const sf::Event event) override;
    void updateLogic(float dt) override;
    void draw(sf::RenderTarget& target) override;
private:
    GameField mField;
    Board mBoard;
};

#endif
