#include"Field.hpp"
#include"constants.hpp"
#include<cassert>

GameField::GameField(){
    mTexture.loadFromFile(CELL_TEXTURE_PATH);
    resizeAndFill(6, 6, 10);
}

void GameField::resizeAndFill(unsigned nFil, unsigned nCol, unsigned mines){
    mNumFils= nFil;
    mNumCols= nCol;
    mMines = mines;
    mIsStarted = false;

    mCells.clear();
    mCells.resize(mNumFils);
    for(unsigned i = 0; i < mNumFils; ++i){
        mCells[i].resize(mNumCols);
        for(unsigned j = 0; j < mNumCols; ++j){
            auto& cell = mCells[i][j];
            cell.setPosition(j* 128, i* 128);
            cell.setTexture(mTexture);
        }
    }
}

void GameField::activate(unsigned fil, unsigned col){
    if(fil< mNumFils && col < mNumCols){
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
            for(unsigned fil = 0; fil < mNumFils; ++fil){
                for(unsigned col = 0; col < mNumCols; ++col){
                    mCells[fil][col].detonate();
                }
            }
        }
        //me falta avisar de juego perdido
    }
}

void GameField::check(unsigned fil, unsigned col){
    if(fil< mNumFils && col < mNumCols){
        mCells[fil][col].check();
    }
}

void GameField::fillMines(unsigned fil, unsigned col){
    auto vector= std::vector<Cell*>();
    const unsigned maxFil= mNumFils-1;
    const unsigned maxCol= mNumCols-1;

    for(unsigned i = 0; i < mNumCols; ++i){
        for(unsigned j = 0; j < mNumCols; ++j){
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
    vector.resize(mMines);
    for(auto cell: vector){
        assert(cell!= nullptr);
        cell->setMines(MINA);
    }
}

void GameField::countMines(){
    for(unsigned fil= 0; fil< mNumFils; ++fil){
        for(unsigned col= 0; col< mNumCols; ++col){
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
    states.transform.combine(getTransform());
    for(const auto& row: mCells){
        for(const auto& cell: row){
            target.draw(cell, states);
        }
    }
}

unsigned GameField::getNumMines(unsigned fil, unsigned col) const{
    if(fil< mNumFils && col< mNumCols){
        if(MINA== mCells[fil][col].mines()){
            return 1;
        }
    }
    return 0;
}