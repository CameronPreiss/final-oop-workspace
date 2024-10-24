#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Helper.hpp"
#include "Goal.hpp"
#include "Robot.hpp"
#include "Obstacle.hpp"
#include <vector>

enum GameState{
    WIN = 0,
    LOSE = 1,
    PLAYING = 2
};

class Game{
    public:
        int width;
        int height;
        std::vector<std::pair<int,int>> obstacleCoordinates;
        Game(int width, int height, std::vector<std::pair<int,int>> obstacleCoordinates){
            this->width = width;
            this->height = height;
            Robot a(width, height);
            Goal b(width-1, height-1);
            Obstacle c(1,2, width, height);
            Obstacle d(3,4, width, height);
            Obstacle e(6,2, width, height);
            GameState::PLAYING;
        }
        bool displayState(){
            if (GameState::WIN){
                std::cout << "You win!" << std::endl;
                return true;
   
            }
            if (GameState::LOSE){
                std::cout << "You win!" << std::endl;
                return true;
 
            }
            if (GameState::PLAYING){
                std::cout << "Game on" << std::endl;
                return false;
            }
        }
        void movePlayer(int dx, int dy){
            //Robot->move(dx,dy);
            if (GameState::PLAYING){

            }
        }

};

#endif