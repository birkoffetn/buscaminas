#include"Button.hpp"
#include"constants.hpp"
#include"utils.hpp"

#include<iostream>

Button::Button(){
    if(!mTexture.loadFromFile(BUTTON_TEXTURE_PATH)){
        std::cout << "Error loading button texture" << std::endl;
    }
    setTexture(mTexture);
    fillRects();
    setTextureRect(mRectsHappy[random(0, mRectsHappy.size()-1)]);
}

bool Button::clicked(sf::Event event){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            if(getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))){
                setTextureRect(mRectsSad[random(ZERO, mRectsSad.size()-1)]);
                return true;
            }
        }
    }
    return false;
}

void Button::fillRects(){
    for(auto i= BUTTON_HAPPY_BEGIN; i< BUTTON_HAPPY_END; ++i){
        for(auto j= 0u; j< BUTTON_WHIDTH_COUNT; ++j){
            mRectsHappy.push_back(sf::IntRect(j*BUTTON_SIZE, i*BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE));
        }
    }
    for(auto i= BUTTON_SAD_BEGIN; i< BUTTON_SAD_END; ++i){
        for(auto j= 0u; j< BUTTON_WHIDTH_COUNT; ++j){
            mRectsSad.push_back(sf::IntRect(j*BUTTON_SIZE, i*BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE));
        }
    }
}