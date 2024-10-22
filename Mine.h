#ifndef MINE_H
#define MINE_H
#include <iostream>
#include <tuple>
#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity{
    public:
    Explosion explode(){
        Explosion explosion(std::get<0>(position), std::get<1>(position));
        explosion.apply(*this);
        return explosion;
    }
    Mine(int x, int y) : GameEntity(x, y, 'M'){}
};

#endif