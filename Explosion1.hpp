#ifndef EXPLOSION1_HPP
#define EXPLOSION1_HPP
#include <iostream>
#include "Effect1.hpp"
#include "GameEntity1.hpp"
#include <utility>

class Explosion : public GameEntity, public Effect{
    public:
        Explosion(int x, int y) : GameEntity(x,y,'E'), Effect() {}
        void apply(GameEntity& entity) override{
            entity.setPos(-1,-1);
            entity.setType('N');
        }
};

#endif