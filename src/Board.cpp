#include"Board.hpp"
#include"constants.hpp"

Board::Board(){
    mFont.loadFromFile(FONT_PATH);

    mCountChecks.setFont(mFont);
    mCountChecks.setCharacterSize(FONT_SIZE);

    mCronometer.setFont(mFont);
    mCronometer.setCharacterSize(FONT_SIZE);

    init(8u, 10u);
}

void Board::init(unsigned fieldWidth, unsigned numMines){
    const auto width= fieldWidth* CELL_SIZE;

    mButton.setOrigin(sf::Vector2f(BUTTON_SIZE/2.f, 0.f));
    mButton.setPosition(sf::Vector2f(width/2.f, 0.f));


}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform.combine(getTransform());

    target.draw(mCountChecks, states);
    target.draw(mCronometer, states);
    target.draw(mButton, states);
}