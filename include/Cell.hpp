#ifndef __CELL_HPP__
#define __CELL_HPP__

#include<SFML/Graphics.hpp>
#include<vector>

enum class State{
    Hide, Show, Check
};

enum Cuadros{Cero, Uno, Dos, Tres, Cuatro, Cinco, 
    Seis, Siete, Ocho, Bandera, Interrogacion, Bomba};

const unsigned MINA= 9;

class Cell: public sf::Sprite{
public:
    Cell();
    void setCoords(unsigned fil, unsigned col);
    unsigned activate();
    void check();
    void setState(State state);
    
    void setMines(unsigned mines){ mMines= mines;}
    unsigned mines() const{ return mMines; }
    State state() const{ return mState; }
private:
    unsigned mFil, mCol, mMines;
    State mState;
    static std::vector<sf::IntRect> rects;
};

#endif