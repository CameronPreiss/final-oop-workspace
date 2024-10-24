#ifndef EFFECT1_HPP
#define EFFECT1_HPP
#include <iostream>
#include "GameEntity1.hpp"

class Effect{
    public:
        virtual void apply(GameEntity& entity) = 0;
};

#endif