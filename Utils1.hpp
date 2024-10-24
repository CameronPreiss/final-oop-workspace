#ifndef UTILS1_HPP
#define UTILS1_HPP
#include <iostream>
#include <utility>
#include <cmath>
#include "GameEntity1.hpp"

class Utils{
    public:
        static std::pair<int, int> generateRandomPos(int gridWidth, int gridHeight){
            int x = std::rand() % gridWidth;
            int y = std::rand() % gridHeight;
            return std::make_pair(x,y);
        }  
        static double calculateDistance(std::pair<int, int> pos1, std::pair<int, int> pos2){
            int x1 = std::get<0>(pos1), y1 = std::get<1>(pos1);
            int x2 = std::get<0>(pos2), y2 = std::get<1>(pos2);
            return std::sqrt(std::pow(y2-y1,2) + std::pow(x2-x1,2));
        }
};

#endif