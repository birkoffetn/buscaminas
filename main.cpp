#include"include/GameField.hpp"
#include"include/Board.hpp"
#include"include/constants.hpp"

#include<SFML/Graphics.hpp>

#include<iostream>

using namespace std;

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    window.setVerticalSyncEnabled(true);

    float valor= -0.2f;
    std::cout<<"valor: "<<valor<<" int: "<<int(valor)<<std::endl;
    std::cout<<"valor: -1"<<" unsigned: "<<unsigned(-1)<<std::endl;

    GameField field(6, 6, 8);
    field.setScale(0.5, 0.5);
    field.setPosition(0, 64);

    Board board;

    window.setSize(sf::Vector2u(384, 448));

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if(event.type == sf::Event::MouseButtonPressed){
                auto pos= field.getInverseTransform().transformPoint(event.mouseButton.x, event.mouseButton.y);
                std::cout<<"x: "<<pos.x<<" y: "<<pos.y<<std::endl;
                unsigned fila= (pos.y< 0.0f? -CELL_SIZE: pos.y)/ CELL_SIZE;
                unsigned columna= (pos.x< 0.0f? -CELL_SIZE: pos.x)/ CELL_SIZE;
                
                std::cout<<"fila: "<<fila<<" columna: "<<columna<<std::endl;
                //std::cout<<field.mines()<<std::endl;
                if(event.mouseButton.button == sf::Mouse::Left){
                    field.activate(fila, columna);
                }
                if(event.mouseButton.button == sf::Mouse::Right){
                    field.check(fila, columna);
                }
            }
        }
        window.clear();
        window.draw(field);
        window.draw(board);
        window.display();
    }
    return EXIT_SUCCESS;
}