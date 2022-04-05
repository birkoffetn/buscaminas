#ifndef __BOARD__HPP__
#define __BOARD__HPP__

#include"Button.hpp"

#include<SFML/Graphics.hpp>

class Board: public sf::Drawable, public sf::Transformable{
public:
    Board();
    void init(unsigned fieldWidth, unsigned numMines);
    void update(float dt);
    void incrementCheck();
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::Text mCountChecks;
    sf::Text mCronometer;
    sf::Font mFont;
    Button mButton;
    float mSecondsElapsed;
    int mChecksRemaining;

};

#endif