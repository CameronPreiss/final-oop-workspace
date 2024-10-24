#ifndef SHIP_HPP
#define SHIP_HPP
#include "GameEntity.hpp"
#include <iostream>
#include <utility>

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