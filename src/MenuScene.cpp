#include"MenuScene.hpp"

#include<iostream>

MenuScene::MenuScene(){
    
}

void MenuScene::init(){
    mFont.loadFromFile(FONT_PATH);
    mTitle.setFont(mFont);
    mTitle.setString("Menu");
    mTitle.setCharacterSize(TITLE_SIZE);
    mTitle.setOrigin(mTitle.getGlobalBounds().width/2, mTitle.getGlobalBounds().height/2);
    auto size= getSize();
    mTitle.setPosition(size.x/ 2.0, 8);
    mTitle.setFillColor(sf::Color::Cyan);


    mOptions.push_back(sf::Text("Continuar", mFont, FONT_SIZE));
    mOptions.push_back(sf::Text("Primera option", mFont, FONT_SIZE));
    mOptions.push_back(sf::Text("Segunda opcion", mFont, FONT_SIZE));
    mOptions.push_back(sf::Text("Tercera opcion", mFont, FONT_SIZE));
    mOptions.push_back(sf::Text("Cuarta opcion", mFont, FONT_SIZE));
    mOptions.push_back(sf::Text("Salir", mFont, FONT_SIZE));

    float top= 128;
    int i= 0;
    for(auto& option: mOptions){
        option.setOrigin(option.getGlobalBounds().width/ 2.0f, option.getGlobalBounds().height/ 2.0f);
        option.setPosition(size.x/ 2.0f, top+ i* 64);
        ++i;
    }
}

int MenuScene::readEvent(const sf::Event event){
    if(event.type == sf::Event::MouseMoved){
        for(auto& option: mOptions){
            if(option.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)){
                option.setFillColor(sf::Color::Red);
            }else{
                option.setFillColor(sf::Color::White);
            }
        }
    }
    if(event.type == sf::Event::MouseButtonPressed){
        for(auto& option: mOptions){
            if(option.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                if(option.getString() == "Salir"){
                    return TERMINATE_APP;
                }
                if(option.getString() == "Continuar"){
                    return CONTINUE_SCENE;
                }
            }
        }
    }
    return CONTINUE_SCENE;
}

void MenuScene::updateLogic(float ){

}

void MenuScene::draw(sf::RenderTarget& target){
    target.draw(mTitle);
    for(auto& option: mOptions){
        target.draw(option);
    }
}
