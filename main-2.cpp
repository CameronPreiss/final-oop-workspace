#include "Ship.hpp"
#include "Mine.hpp"
#include "Explosion.hpp"
#include "Utils.hpp"

int main(){
    Ship a(0,2);
    Mine b(4,6);

    a.move(1,0);
    std::cout << Utils::calculateDistance(a.getPos(), b.getPos()) << std::endl;

    Explosion c(3,3);
    c.apply(a);
}