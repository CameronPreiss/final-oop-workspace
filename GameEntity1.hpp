#ifndef GAMEENTITY1_HPP
#define GAMEENTITY1_HPP
#include <iostream>
#include <utility>

enum GameEntityType{
    ExplosionType = 0,
    MineType = 1,
    NoneType = 2,
    ShipType = 3
};

class GameEntity{
    private:
        std::pair<int, int> position;
        GameEntityType type;
    public:
        GameEntity(int x, int y, char tmpType){
            position = std::make_pair(x,y);
            switch (tmpType){
                case 'E':
                    this->type = ExplosionType;
                    break;
                case 'M':
                    this->type = MineType;
                    break;
                case 'N':
                    this->type = NoneType;
                    break;
                case 'S':
                    this->type = ShipType;
                    break;
            }
        }
        std::pair<int, int> getPos(){
            return position;
        }
        GameEntityType getType(){
            return type;
        }
        void setPos(int x, int y){
            position = std::make_pair(x,y);
        }
        void setType(char tmpType){
            switch (tmpType){
                case 'E':
                    this->type = ExplosionType;
                    break;
                case 'M':
                    this->type = MineType;
                    break;
                case 'N':
                    this->type = NoneType;
                    break;
                case 'S':
                    this->type = ShipType;
                    break;
            }
        }
};

#endif