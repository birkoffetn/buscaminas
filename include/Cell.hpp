#ifndef __CELL_HPP__
#define __CELL_HPP__

#include<SFML/Graphics.hpp>
#include<vector>

enum CellState{
    Hide, Show, Check
};

enum Cuadros{Cero, Uno, Dos, Tres, Cuatro, Cinco, 
    Seis, Siete, Ocho, Bandera, Interrogacion, Bomba};

const unsigned MINA= 9;

class Cell: public sf::Sprite{
public:
    Cell();
    unsigned activate();
    void check();
    void detonate();
    
    void setMines(unsigned mines){ mMines= mines;}
    unsigned mines() const{ return mMines; }

private:
    unsigned mMines;
    State mState;

    static std::vector<sf::IntRect> rects;

    CellState state() const{ return mState; }
    void setState(State state);
};

#endif