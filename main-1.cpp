#include "GameEntity.hpp"
#include "Effect.hpp"
#include "Utils.hpp"

int main(){
    GameEntity a(1,2,'N');
    GameEntity b(4,6,'M');

    std::cout << Utils::calculateDistance(a.getPos(), b.getPos()) << std::endl;
    
}