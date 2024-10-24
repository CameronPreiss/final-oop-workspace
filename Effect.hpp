#ifndef EFFECT_HPP
#define EFFECT_HPP
#include <iostream>
#include "GameEntity.hpp"

class Effect{
    public:
        virtual void apply(GameEntity& entity) = 0;
};

#endif