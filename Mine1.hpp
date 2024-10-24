#ifndef MINE1_HPP
#define MINE1_HPP
#include <utility>
#include <iostream>
#include "GameEntity1.hpp"
#include "Explosion1.hpp"

class Mine : public GameEntity{
    public:
        Explosion explode(){
            Explosion a(std::get<0>(getPos()), std::get<1>(getPos()));
            setType('N');
            return a;
        }
        Mine(int x, int y) : GameEntity(x,y,'M') {}
};

#endif