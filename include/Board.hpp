#ifndef __BOARD__HPP__
#define __BOARD__HPP__

#include"Button.hpp"

#include<SFML/Graphics.hpp>

class Board: public sf::Drawable, public sf::Transformable{
public:
    Board();
    void initialize(unsigned numMines, unsigned width);
    void update(float dt);
    void incrementCheck(int nChecks);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::Text mCounter;
    sf::Text mCronometer;
    sf::Font mFont;
    Button mButton;
    float mSecondsElapsed;
    int mMinesRemaining;

    sf::String counterToString() const;
    sf::String cronometerToString() const;
};

#endif