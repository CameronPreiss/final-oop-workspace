#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP
#include <iostream>
#include <utility>
#include <cmath>
#include "GridItem.hpp"
#include "Robot.hpp"

enum InteractableType{
    GOAL = 0,
    OBSTACLE = 1
};

static int interactableCount = 0;

class Interactable : public GridItem{
    public:
        Interactable(int x, int y, int width, int height) : GridItem(x,y,width,height){
            interactableCount++;
        }
        Interactable(){
            x = 0;
            y = 0;
            width = 0;
            height = 0;
            interactableCount++;
        }
        virtual bool interact(Robot* player) = 0;
        virtual InteractableType getType() = 0;
        int getActiveInteractableCount(){
            return interactableCount;
        }
        ~Interactable(){
            interactableCount--;
        }


};

#endif