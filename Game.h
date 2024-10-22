#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <tuple>
#include <vector>
#include "GameEntity.h"
#include "Ship.h"
#include "Utils.h"
#include "Mine.h"
#include "Explosion.h"

class Game{
    public:
        std::vector<GameEntity*> entities;
        std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight){
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
            bool everyShipDestroyed = false;
            int count = 0;
            while (count <= maxIterations && everyShipDestroyed == false){
            for (auto* entity : entities) {
                if (Ship* ship = dynamic_cast<Ship*>(entity)) {
                    ship->move(1, 0);
                }
            }
            for (auto* shipEntity : entities) {
                if (Ship* ship = dynamic_cast<Ship*>(shipEntity)) {
                    for (auto* mineEntity : entities) {
                        if (Mine* mine = dynamic_cast<Mine*>(mineEntity)) {
                            double distance = Utils::calculateDistance(ship->getPos(), mine->getPos());
                            if (distance <= mineDistanceThreshold && mine->getType() != NoneType) {
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                            }
                        }
                    }
                }
            }

            bool everyShipDestroyed = true;
            for (auto* entity : entities){
                if (entity->getType() == ShipType){
                    everyShipDestroyed = false;
                    break;
                }
            }

            count++;
            }
        }

        ~Game(){
            for (auto* entity : entities){
                delete entity;
            }
        }

        std::vector<GameEntity*> get_entities(){
            return entities;
        }

        void set_entities(std::vector<GameEntity*> entities){
            this->entities = entities;
        }
};

#endif