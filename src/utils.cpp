#include"utils.hpp"

#include<random>

unsigned random(unsigned min, unsigned max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
