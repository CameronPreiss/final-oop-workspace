#include "GridItem.hpp"
#include "Helper.hpp"

int main(){
    GridItem a(1,2,3,4);
    GridItem b(4,6,7,8);
    Helper c;
    std::cout << c.euclideanDistance(a.getCoordinates(), b.getCoordinates()) << std::endl;
}