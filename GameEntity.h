#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <iostream>
#include <cmath>
#include <tuple>

enum GameEntityType : char{
    ExplosionType,
    MineType,
    NoneType,
    ShipType
};

class GameEntity{
    public:
        std::tuple<int, int> position;
        GameEntityType type;
        GameEntity(int x, int y, char tmpType){
            position = std::make_tuple(x,y);
            switch(tmpType){
                case 'E':
                    this->type = GameEntityType::ExplosionType;
                    break;
                case 'M':
                    this->type = GameEntityType::MineType;
                    break;
                case 'S':
                    this->type = GameEntityType::ShipType;
                    std::cout << this->type << std::endl;
                    break;  
                default:
                    this->type = GameEntityType::NoneType;   
                    break;                               
            }
        }
        std::tuple<int, int> getPos(){
            return position;
        }
        GameEntityType getType(){
            return type;
        }

        virtual ~GameEntity() {}
        void setType(char type) {
        switch (type) {
            case 'E':
                this->type = GameEntityType::ExplosionType;
                break;
            case 'M':
                this->type = GameEntityType::MineType;
                break;
            case 'N':
                this->type = GameEntityType::NoneType;
                break;
            case 'S':
                this->type = GameEntityType::ShipType;
                break;
            }
        }
        void setPosition(int x, int y){
            std::tuple<int, int> posNew = {x,y};
            this->position = posNew;
        }
};

#endif