#ifndef __GAMEFIELD_HPP__
#define __GAMEFIELD_HPP__

#include"Field.hpp"
#include"Cell.hpp"

#include<SFML/Graphics.hpp>
#include<algorithm>
#include<vector>
#include<random>

class GameField: public sf::Drawable, public sf::Transformable{
public:
    GameField();
    void resizeAndFill(unsigned fil, unsigned col, unsigned mines);
    void activate(unsigned fil, unsigned col);
    void check(unsigned fil, unsigned col);
protected:
    void fillMines(unsigned fil, unsigned col);
    void countMines();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    unsigned mNumFils, mNumCols, mMines;
    std::vector<std::vector<Cell>> mCells;
    sf::Texture mTexture;
    bool mIsStarted;

    unsigned getNumMines(unsigned fil, unsigned col) const;
};

#endif
