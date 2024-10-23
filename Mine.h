#ifndef MINE_H
#define MINE_H
#include <iostream>
#include "GameEntity.h"
#include "Explosion.h"
#include <tuple>

class Mine : public GameEntity{
    public:
        Explosion explode(){
            std::tuple<int, int> b = getPos();
            Explosion a(std::get<0>(b), std::get<1>(b));
            setType('N');
            return a;
        }
        Mine(int x, int y) : GameEntity(x,y,'M') {}
};

#endif