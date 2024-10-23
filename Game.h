#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <tuple>
#include "GameEntity.h"
#include "Utils.h"
#include "Mine.h"
#include "Ship.h"
#include "Explosion.h"

class Game{
    private:
        std::vector<GameEntity*> entities;
    public:
    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight){
        //std::cout << "Game intialising" << std::endl;
        for (int i = 0; i < numShips; i++){
            std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }
        for (int i = 0; i < numMines; i++){
            std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }
        return entities;
    }
    void gameLoop(int maxIterations, double mineDistanceThreshold){
        int count = 0;
        bool everyShipDestroyed = false;
        while (count <= maxIterations && everyShipDestroyed == false){
            //std::cout << "iteration no. " << count << std::endl;
            for (auto* entity : get_entities()){
                if (Ship* ship = dynamic_cast<Ship*>(entity)){
                    ship->move(1,0);
                }
            }
            for (auto* entity : get_entities()){
                if (Ship* ship = dynamic_cast<Ship*>(entity)){
                if (ship->getType() == GameEntityType::ShipType){
                    for (auto* entity1 : get_entities()){
                        if (Mine* mine = dynamic_cast<Mine*>(entity1)){
                            double dist = Utils::calculateDistance(mine->getPos(), ship->getPos());
                            if (dist <= mineDistanceThreshold && mine->getType() != NoneType){
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                                //std::cout << "Mine exploded " << std::endl;
                            }
                        }
                    }
                }
                }
            }
            //std::cout << "oi" << std::endl;
            bool shipsGone = true;
            for (auto* entity : get_entities()){
                if (Ship* ship = dynamic_cast<Ship*>(entity)){
                if (ship->getType() == GameEntityType::ShipType){
                    shipsGone = false;
                }
                }
            }
            if (shipsGone == true){
                everyShipDestroyed = true;
            }
            count++;
        }
        //std::cout << "Game ended" << std::endl;
    }
    std::vector<GameEntity*> get_entities(){
        return entities;
    }
    void set_entities(std::vector<GameEntity*> entities){
        this->entities = entities;
    }
};

#endif