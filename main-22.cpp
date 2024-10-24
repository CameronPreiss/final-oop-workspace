#include "Ship1.hpp"
#include "Mine1.hpp"
#include "Explosion1.hpp"
#include "Utils1.hpp"

int main(){
    Ship a(1,2);
    Mine b(4,6);

    Explosion c(3,3);
    c.apply(a);
}