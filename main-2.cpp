#include "Explosion.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

int main(){
    Ship a_temp(1,2);
    GameEntity* a = ((GameEntity*)&a_temp);
    Mine b(4,6);

    Explosion c = b.explode();
    c.apply(*a);

    std::cout << (int) a->getType() << std::endl;
}