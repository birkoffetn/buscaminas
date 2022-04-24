#include"Button.hpp"
#include"constants.hpp"
#include"utils.hpp"

#include<iostream>

Button::Button(){
    mTexture.loadFromFile(BUTTON_TEXTURE_PATH);
    
    setTexture(mTexture);
    fillRects();
    makeHappy();
}

void Button::makeSad(){
    setTextureRect(mRectsSad[random(0, mRectsSad.size()-1)]);
}

void Button::makeHappy(){
    setTextureRect(mRectsHappy[random(0, mRectsHappy.size()-1)]);
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