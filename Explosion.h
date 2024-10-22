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
            entity.setPosition(-1, -1);
            entity.type = GameEntityType::NoneType;
            //std::cout << "apply" << std::endl;
        } 
};


#endif