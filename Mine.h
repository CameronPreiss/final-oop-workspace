#ifndef MINE_H
#define MINE_H
#include <iostream>
#include <tuple>
#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity{
    public:
    Explosion explode(){
        Explosion a(std::get<0>(position), std::get<1>(position));
        a.setType('N');
        std::cout << "exploded" << std::endl;
        return a;

    }
    Mine(int x, int y) : GameEntity(x, y, 'M'){}
};

#endif