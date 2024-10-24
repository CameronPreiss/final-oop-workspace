#include "GameEntity1.hpp"
#include "Utils1.hpp"

int main(){
    std::pair<int, int> position1 = Utils::generateRandomPos(10,10);
    std::pair<int, int> position2 = Utils::generateRandomPos(10,10);
    GameEntity a(std::get<0>(position1), std::get<1>(position1), 'S');
    GameEntity b(std::get<0>(position2), std::get<1>(position2), 'S');
    std::cout << Utils::calculateDistance(a.getPos(), b.getPos()) << std::endl;
}