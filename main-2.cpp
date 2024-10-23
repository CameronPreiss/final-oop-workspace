#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main(){
    Ship a(1,2);
    Mine b(4,6);
    Explosion c(3,3);

    c.apply(a);
    std::cout << a.getType() << std::endl;
}