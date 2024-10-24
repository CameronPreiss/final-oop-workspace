#ifndef GAME_H
#define GAME_H
#include "GameEntity.hpp"
#include "Utils.hpp"
#include "Explosion.hpp"
#include "Mine.hpp"
#include "Ship.hpp"
#include <vector>
#include <utility>
#include <iostream>

class Game{
    private:
        std::vector<GameEntity*> entities;
    public:
        std::vector<GameEntity*> get_entities(){
            return entities;
        }
        void set_entities(std::vector<GameEntity*> entities){
            this->entities = entities;
        }
        std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight){
            std::cout << "Initialising game" << std::endl;
            for (int i = 0; i < numShips; i++){
                std::pair<int, int> position = Utils::generateRandomPos(gridWidth, gridHeight);
                entities.push_back(new Ship(std::get<0>(position), std::get<1>(position)));
            }
            for (int i = 0; i < numMines; i++){
                std::pair<int, int> position = Utils::generateRandomPos(gridWidth, gridHeight);
                entities.push_back(new Mine(std::get<0>(position), std::get<1>(position)));
            }
            return entities;
        }
        void gameLoop(int maxIterations, double mineDistanceThreshold){
            int count = 0;
            bool allShipsDestroyed = false;
            while (count < maxIterations && allShipsDestroyed == false){
                std::cout << "Iteration no. " << count + 1 << std::endl;
                for (auto* entity : get_entities()){
                    Ship* ship = (Ship*) entity;
                    if (ship->getType() == GameEntityType::ShipType){
                        ship->move(1,0);
                    }
                }
                allShipsDestroyed = true;
                for (auto* entity : get_entities()){
                    Ship* ship = (Ship*) entity;
                    if (ship->getType() == GameEntityType::ShipType){
                        allShipsDestroyed = false;
                        for (auto* entity1 : get_entities()){
                            Mine* mine = (Mine*) entity1;
                            if (mine->getType() == GameEntityType::MineType){
                                if (Utils::calculateDistance(mine->getPos(), ship->getPos()) >= mineDistanceThreshold){
                                    Explosion explosion = mine->explode();
                                    explosion.apply(*ship);
                                }
                            }
                        }
                    }
                }
                if (allShipsDestroyed == true){
                    std::cout << "Game Over" << std::endl;
                }
                count++;
            }
        }

};

#endif