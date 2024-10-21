#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"
#include <iostream>
#include <tuple>

int main(){
    Utils a;
    std::tuple<int, int> randomPos = a.generateRandomPos(10,10);
    std::tuple<int, int> randomPos2 = a.generateRandomPos(10,10);
    std::cout << a.calculateDistance(randomPos, randomPos2) << std::endl;
    
}