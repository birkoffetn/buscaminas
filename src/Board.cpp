#include"Board.hpp"
#include"constants.hpp"

#include<iomanip>
#include<sstream>

Board::Board(){
    mFont.loadFromFile(FONT_PATH);
    mCounter.setFont(mFont);
    mCounter.setCharacterSize(FONT_SIZE);
    mCronometer.setFont(mFont);
    mCronometer.setCharacterSize(FONT_SIZE);
}

void Board::initialize(unsigned numMines, unsigned width){
    mButton.setOrigin(sf::Vector2f(BUTTON_SIZE/2.f, 0.f));
    mButton.setPosition(sf::Vector2f(width/2.f, 0.f));

    mCronometer.setOrigin(mCronometer.getLocalBounds().width, 0.f);
    mCronometer.setPosition(width, 0.0f);

    mSecondsElapsed= 0.0f;
    mCronometer.setString(cronometerToString());

    mMinesRemaining= numMines;
    mCounter.setString(counterToString());
}

void Board::update(float dt){
    mSecondsElapsed+= dt;
    mCronometer.setString(cronometerToString());
}

void Board::incrementCheck(int nChecks){
    mMinesRemaining+= nChecks;
    mCounter.setString(counterToString());
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform.combine(getTransform());
    target.draw(mCounter, states);
    target.draw(mCronometer, states);
    target.draw(mButton, states);
}

sf::String Board::counterToString() const{
    std::ostringstream output;
    output.fill('0');
    output<<std::setw(3)<<mMinesRemaining;
    return sf::String(output.str().c_str());
}

sf::String Board::cronometerToString() const{
    int mm= int(mSecondsElapsed)/ 60;
    int ss= int(mSecondsElapsed)% 60;
    std::ostringstream output;
    output.fill('0');
    output<<std::setw(2)<<mm<<":"<<std::setw(2)<<ss;
    return sf::String(output.str().c_str());
}
