#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <cmath>
#include <tuple>

class Utils{
    public:
        static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight){
            int x = std::rand() % gridWidth;
            int y = std::rand() % gridHeight;
            return std::make_tuple(x,y);
        }
        static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int,int> pos2){
            int x1 = std::get<0>(pos1), y1 = std::get<1>(pos1);
            int x2 = std::get<0>(pos2), y2 = std::get<1>(pos2);
            return std::sqrt(std::pow(y2-y1, 2) + std::pow(x2-x1, 2));
        }
};

#endif