#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include "GridItem.hpp"
#include <utility>

class Robot : public GridItem{
    public:
        int health;
        Robot(int gridWidth, int gridHeight) : GridItem(0,0,gridWidth, gridHeight) {
            health = 3;
        }
        int getHealth(){
            if (health < 0){
                health = 0;
            }
            return health;
        }
        void takeHit(){
            health--;
        }
        bool move(int xOffset, int yOffset){
            if (xOffset == 0 || yOffset == 0){
                int x = std::get<0>(coordinates) + xOffset;
                int y = std::get<1>(coordinates) + yOffset;
                if (x > width || x <0 || y >height || y<0){
                    return false;
                }
                coordinates = std::make_pair(x,y);
                return true;
            } else {
                return false;
            }
        }
};

#endif