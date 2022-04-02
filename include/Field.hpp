#ifndef __FIELD_HPP__
#define __FIELD_HPP__


class Field{
public:
    virtual void activate(unsigned fil, unsigned col)= 0;
    
    virtual void check(unsigned fil, unsigned col)= 0;
    virtual ~Field(){}
protected:
    
    virtual void fillMines(unsigned fil, unsigned col)= 0;
    
    virtual void countMines()= 0;
};


#endif