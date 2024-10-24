#ifndef MINE_HPP
#define MINE_HPP
#include <iostream>
#include "GameEntity.hpp"
#include <utility>
#include "Explosion.hpp"

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