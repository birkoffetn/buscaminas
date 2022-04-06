#include"Game.hpp"
#include"constants.hpp"

int Game::run(){
    while(mWindow.isOpen()){
        readInput();
        updateLogic(mClock.restart().asSeconds());
        draw();
    }
    return 0;
}

void Game::readInput(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        if(event.type== sf::Event::Closed){
            mWindow.close();
        }
        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            mWindow.setView(sf::View(visibleArea));
        }
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
    } 
}

void Game::updateLogic(float dt){
    // update the logic
}

void Game::draw(){
    mWindow.clear();
    mWindow.draw(mField);
    mWindow.draw(mBoard);
    mWindow.display();
}