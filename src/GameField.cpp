#include"GameField.hpp"
#include<cassert>

GameField::GameField(unsigned nFil, unsigned nCol, unsigned mines){
    mNumFil= nFil;
    mNumCol= nCol;
    mTexture.loadFromFile("assets/casillas.png");

    mCells.resize(numFil());
    for(unsigned i = 0; i < numFil(); ++i){
        mCells[i].resize(numCol());
        for(unsigned j = 0; j < numCol(); ++j){
            auto& cell = mCells[i][j];
            cell.setCoords(i, j);
            cell.setPosition(j* 128, i* 128);
            cell.setTexture(mTexture);
            cell.setState(State::Hide);
        }
    }
    mMines = mines;
    mIsStarted = false;
}

void GameField::activate(unsigned fil, unsigned col){
    if(fil< numFil() && col < numCol()){
        if(false== mIsStarted){
            fillMines(fil, col);
            countMines();
            mIsStarted = true;
        }
        auto& cell = mCells[fil][col];
        if(cell.state()== State::Show || cell.state()== State::Check){
            return;
        }

        auto mines= cell.activate();
        if(mines == 0){
            activate(fil-1, col-1);
            activate(fil-1, col);
            activate(fil-1, col+1);
            activate(fil, col-1);
            activate(fil, col+1);
            activate(fil+1, col-1);
            activate(fil+1, col);
            activate(fil+1, col+1);
        }
        else if(mines== MINA){
            for(unsigned fil = 0; fil < numFil(); ++fil){
                for(unsigned col = 0; col < numCol(); ++col){
                    auto& cell= mCells[fil][col];
                    if(cell.mines() == MINA){
                        cell.activate();
                    }
                }
            }
        }
        //me falta avisar de juego perdido
    }
}

void GameField::check(unsigned fil, unsigned col){
    if(fil< numFil() && col < numCol()){
        mCells[fil][col].check();
    }
}

void GameField::fillMines(unsigned fil, unsigned col){
    auto vector= std::vector<Cell*>();
    const unsigned maxFil= numFil()-1;
    const unsigned maxCol= numCol()-1;

    for(unsigned i = 0; i < numFil(); ++i){
        for(unsigned j = 0; j < numCol(); ++j){
            auto left= j> 0? j- 1: 0;
            auto right= j< maxCol? j+ 1: j;
            auto top= i> 0? i- 1: 0;
            auto bottom= i< maxFil? i+ 1: i;
            if(left<= col && col<= right && top<= fil && fil<= bottom){
                continue;
            }
            vector.push_back(&mCells[i][j]);
        }
    }
    assert(vector.size()>= mMines);
    std::shuffle(vector.begin(), vector.end(), std::mt19937{std::random_device{}()});
    vector.resize(mines());
    for(auto cell: vector){
        assert(cell!= nullptr);
        cell->setMines(MINA);
    }
}

void GameField::countMines(){
    for(unsigned fil= 0; fil< numFil(); ++fil){
        for(unsigned col= 0; col< numCol(); ++col){
            auto& cell= mCells[fil][col];
            if(cell.mines() == MINA){
                continue;
            }
            auto cont= getNumMines(fil-1, col-1);
            cont+= getNumMines(fil-1, col);
            cont+= getNumMines(fil-1, col+1);
            cont+= getNumMines(fil, col-1);
            cont+= getNumMines(fil, col+1);
            cont+= getNumMines(fil+1, col-1);
            cont+= getNumMines(fil+1, col);
            cont+= getNumMines(fil+1, col+1);
            cell.setMines(cont);
        }
    }
}

void GameField::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(const auto& row: mCells){
        //states.transform*= getTransform();
        for(const auto& cell: row){
            target.draw(cell, getTransform());
        }
    }
}

unsigned GameField::getNumMines(unsigned fil, unsigned col) const{
    if(fil< numFil() && col< numCol()){
        if(MINA== mCells[fil][col].mines()){
            return 1;
        }
    }
    return 0;
}