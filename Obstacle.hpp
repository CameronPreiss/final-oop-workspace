#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <iostream>
#include "Interactable.hpp"
#include <utility>
#include "Robot.hpp"
#include "Helper.hpp"

class Obstacle : public Interactable{
    public:
        Obstacle(int x, int y, int width, int height){
            this->x = x;
            this->y = y;
            coordinates = std::make_pair(x,y);
            this->width = width;
            this->height = height;
        }
        bool interact(Robot* player) override{
            if (Helper::euclideanDistance(getCoordinates(), player->getCoordinates()) == 0){
                player->takeHit();
                if (player->getHealth() == 0){
                    return true;
                }
            } else {
                return false;
            }
            return false;
        }
        InteractableType getType(){
            return InteractableType::OBSTACLE;
        }
};

#endif