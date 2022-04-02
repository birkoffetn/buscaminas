#ifndef __GAMEFIELD_HPP__
#define __GAMEFIELD_HPP__

#include"Field.hpp"
#include"Cell.hpp"

#include<SFML/Graphics.hpp>
#include<algorithm>
#include<vector>
#include<random>

class GameField: public Field, public sf::Drawable, public sf::Transformable{
public:
    /**@brief Constructor principal.*/
    GameField(unsigned fil, unsigned col, unsigned mines);
    /**@brief Descubre el contenido de una casilla en funcion de su posicion.*/
    void activate(unsigned fil, unsigned col) override;
    /**@brief Marca con una bandera una celda oculta en funcion de su posicion.*/
    void check(unsigned fil, unsigned col) override;
    unsigned numFil() const{ return mNumFil; }
    unsigned numCol() const{ return mNumCol; }
    unsigned mines() const{ return mMines; }
protected:
    /**@brief Rellena el campo con una cantidad de minas determinada de forma aleatoria.*/
    void fillMines(unsigned fil, unsigned col) override;
    /**@brief Recorre cada celda del campo y cuenta cuantas minas hay alrededor.*/
    void countMines() override;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    unsigned mMines;
    std::vector<std::vector<Cell>> mCells;
    unsigned mNumFil, mNumCol;
    sf::Texture mTexture;
    bool mIsStarted;

    unsigned getNumMines(unsigned fil, unsigned col) const;
};

#endif