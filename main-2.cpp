#include "Explosion.h"
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

int main(){
    Ship a(1,2);
    Mine b(4,6);

    Explosion c = b.explode();
    c.apply(a);

}