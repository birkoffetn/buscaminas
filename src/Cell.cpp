#include"Cell.hpp"

std::vector<sf::IntRect> Cell::rects= {
    sf::IntRect(0, 0, 128, 128),
    sf::IntRect(128, 0, 128, 128),
    sf::IntRect(256, 0, 128, 128),
    sf::IntRect(384, 0, 128, 128),
    sf::IntRect(512, 0, 128, 128),
    sf::IntRect(640, 0, 128, 128),
    sf::IntRect(0, 128, 128, 128),
    sf::IntRect(128, 128, 128, 128),
    sf::IntRect(256, 128, 128, 128),
    sf::IntRect(384, 128, 128, 128),
    sf::IntRect(512, 128, 128, 128),
    sf::IntRect(640, 128, 128, 128)
};

Cell::Cell(){
    mMines = 0;
    setState(State::Hide);
}

unsigned Cell::activate(){
    if(state() == State::Hide){
        setState(State::Show);
    }
    return mMines;
}

void Cell::check(){
    if(state() == State::Hide){
        setState(State::Check);
    }
    else if(state()== State::Check){
        setState(State::Hide);
    }
}

void Cell::setState(CellState state){
    mState = state;
    switch(mState) {
        case State::Hide:
            setTextureRect(rects.at(Cuadros::Cero));
            break;
        case State::Show:
            setColor(sf::Color::Cyan);
            setTextureRect(rects.at(mines()== 9? Cuadros::Bomba: mines()));
            break;
        case State::Check:
            setTextureRect(rects.at(Cuadros::Bandera));
            break;
    }
}

void Cell::detonate(){
    if(mines()== MINA){
        mState= State::Show;
        setTextureRect(rects.at(Cuadros::Bomba));
        setColor(sf::Color::Red);
    }
}
