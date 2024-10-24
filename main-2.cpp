#include "Obstacle.hpp"
#include "Goal.hpp"
#include "Interactable.hpp"
#include "Robot.hpp"

int main(){
    Robot a(1,2);
    Goal b(1,2);
    Obstacle c(2,2,1,1);
    a.getHealth();
    std::cout << b.interact(&a) << std::endl;
    a.move(1,0);
    std::cout << c.interact(&a) << std::endl;
}