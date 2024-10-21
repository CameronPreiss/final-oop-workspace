#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <iostream>
#include <tuple>
#include "GameEntity.h"
#include "Effect.h"

class Explosion : public GameEntity, public Effect{
    public:
        Explosion(int x, int y) : GameEntity(x, y, 'E'){}
        void apply(GameEntity& entity) override{
            position = std::make_tuple(-1,-1);
            type = GameEntityType::NoneType;
        } 
};


#endif