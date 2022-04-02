#include"include/GameField.hpp"
#include<SFML/Graphics.hpp>

#include<iostream>

using namespace std;

int main(){

    sf::RenderWindow window(sf::VideoMode(1024, 768), "Minesweeper");
    window.setVerticalSyncEnabled(true);

    GameField field(5, 5, 5);
    //field.setScale(0.3, 0.3);

    sf::Texture texture;
    texture.loadFromFile("assets/casillas.png");

    Cell cell;
    cell.setTexture(texture);
    cell.setTextureRect(sf::IntRect(0, 0, 128, 128));
    cell.setPosition(100, 100);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed){
                auto fila= event.mouseButton.x/128;
                auto columna= event.mouseButton.y/128;
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
        window.display();
    }
    return EXIT_SUCCESS;
}