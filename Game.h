#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Helper.hpp"
#include "Goal.hpp"
#include "Robot.hpp"
#include "Obstacle.hpp"

enum GameState{
    WIN = 0,
    LOSE = 1,
    PLAYING = 2
}

class Game{
    public:
        std::vector<std::pair<int,int>> obstacleCoordinates;
        Game(int width, int height, std::vector<std::pair<int,int>> obstacleCoordinates){

        }
}

#endif