#include"GameScene.hpp"

void GameScene::init(){
    mField.setPosition(sf::Vector2f(0, 64));
    mField.setScale(0.5, 0.5);
    resize(384, 448);
}

int GameScene::readEvent(const sf::Event event){
    if(event.type == sf::Event::MouseButtonPressed){
        auto pos= mField.getInverseTransform().transformPoint(event.mouseButton.x, event.mouseButton.y);
        unsigned fila= (pos.y< 0.0f? -CELL_SIZE: pos.y)/ CELL_SIZE;
        unsigned columna= (pos.x< 0.0f? -CELL_SIZE: pos.x)/ CELL_SIZE;
        
        if(event.mouseButton.button == sf::Mouse::Left){
            mField.activate(fila, columna);
        }
        if(event.mouseButton.button == sf::Mouse::Right){
            mField.check(fila, columna);
        }
    }
    return CONTINUE_SCENE;
}

void GameScene::updateLogic(float){

}

void GameScene::draw(sf::RenderTarget& target){
    target.draw(mField);
    target.draw(mBoard);
}
