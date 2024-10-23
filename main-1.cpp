#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"
#include <iostream>
#include <tuple>

int main(){
    GameEntity a(1,2,'M');
    Utils d;
    std::tuple<int, int> b = d.generateRandomPos(10, 10);
    std::tuple<int, int> c = d.generateRandomPos(10,10);

    std::cout << d.calculateDistance(b,c) << std::endl;
}