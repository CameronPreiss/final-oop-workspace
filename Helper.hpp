#ifndef HELPER_HPP
#define HELPER_HPP
#include <iostream>
#include <utility>
#include "GridItem.hpp"
#include <cmath>

class Helper{
    public:
        static double euclideanDistance(std::pair<int, int> item1, std::pair<int, int> item2){
            int x1 = std::get<0>(item1), y1 = std::get<1>(item1);
            int x2 = std::get<0>(item2), y2 = std::get<1>(item2);
            return std::sqrt(std::pow(x2-x1,2) + std::pow(y2-y1,2));
        }
};

#endif