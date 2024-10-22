#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <iostream>
#include <tuple>
#include "GameEntity.h"
#include "Effect.h"

class Explosion : public GameEntity, public Effect{
    public:
        Explosion(int x, int y) : GameEntity(x, y, 'E'), Effect(){};
        void apply(GameEntity& entity) override{
            entity.position = std::make_tuple(-1,-1);
            entity.type = GameEntityType::NoneType;
        } 
};


#endif