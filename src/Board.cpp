#include"Board.hpp"
#include"constants.hpp"

#include<iostream>

Board::Board(){

    mFont.loadFromFile(FONT_PATH);
      

    mCountChecks.setFont(mFont);
    mCountChecks.setCharacterSize(FONT_SIZE);
    mCountChecks.setString("000");

    mCronometer.setFont(mFont);
    mCronometer.setCharacterSize(FONT_SIZE);
    mCronometer.setString("00:00");



    init(6* 128/ 2);
}

void Board::init(unsigned width){
    mButton.setOrigin(sf::Vector2f(BUTTON_SIZE/2.f, 0.f));
    mButton.setPosition(sf::Vector2f(width/2.f, 0.f));

    mCronometer.setOrigin(mCronometer.getLocalBounds().width, 0.f);
    mCronometer.setPosition(width, 0.0f);

}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform.combine(getTransform());

    target.draw(mCountChecks, states);
    target.draw(mCronometer, states);
    target.draw(mButton, states);
}