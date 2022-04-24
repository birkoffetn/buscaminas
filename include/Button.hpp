#ifndef __BUTTON__HPP__
#define __BUTTON__HPP__

#include<SFML/Graphics.hpp>
#include<vector>

class Button: public sf::Sprite{
public:
    Button();
    void makeSad();
    void makeHappy();
private:
    sf::Texture mTexture;
    std::vector<sf::IntRect> mRectsHappy;
    std::vector<sf::IntRect> mRectsSad;
    void fillRects();
};

#endif