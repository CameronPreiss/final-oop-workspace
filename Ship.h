#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <tuple>
#include "GameEntity.h"

class Ship : public GameEntity{
    public:
        void move(int dx, int dy){
            int x = std::get<0>(position) + dx; 
            int y = std::get<1>(position) + dy;
            setPosition(x, y);
            //std::cout << "moved" << std::endl;
        }
        Ship(int x, int y) : GameEntity(x, y, 'S'){}
};

#endif