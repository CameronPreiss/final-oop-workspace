#ifndef GOAL_HPP
#define GOAL_HPP
#include "Interactable.hpp"
#include <iostream>
#include "Helper.hpp"
#include <utility>
#include "Robot.hpp"

class Goal : public Interactable{
    public:
        Goal(int width, int height){
            this->width = width;
            this->height = height;
            coordinates = std::make_pair(width -1, height -1);
        }
        bool interact(Robot* player) override{
            if (Helper::euclideanDistance(getCoordinates(), player->getCoordinates()) == 0){
                return true;
            } else {
                return false;
            }
        }
        InteractableType getType(){
            return InteractableType::GOAL;
        }
};

#endif