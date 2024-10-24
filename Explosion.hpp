#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
#include <iostream>
#include <utility>
#include "GameEntity.hpp"
#include "Effect.hpp"

class Explosion : public GameEntity, public Effect{
    public:
        Explosion(int x, int y) : GameEntity(x,y,'E'), Effect() {}
        void apply(GameEntity& entity){
            entity.setPos(-1,-1);
            entity.setType('N');
        }
};

#endif