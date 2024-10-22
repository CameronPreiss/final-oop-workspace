#include "Explosion.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

int main(){
    Ship a(1,2);
    Mine b(4,6);

    a.move(2,3);
    b.explode();

    Explosion c(3,3);
    c.apply(a);

    std::cout << c.getType() << std::endl;
}