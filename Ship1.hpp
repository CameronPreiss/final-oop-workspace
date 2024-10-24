#ifndef SHIP1_HPP
#define SHIP1_HPP
#include <iostream>
#include <utility>
#include "GameEntity1.hpp"

class Ship : public GameEntity{
    public:
        void move(int dx, int dy){
            int x = std::get<0>(getPos()) + dx;
            int y = std::get<1>(getPos()) + dy;
            setPos(x,y);
        }
        Ship(int x, int y) : GameEntity(x,y,'S') {}
};

#endif