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
        GameEntity(int x, int y, char type){
            position = std::make_tuple(x,y);
            switch(type){
                case 'E':
                    type = 0;
                    break;
                case 'M':
                    type = 1;
                    break;
                case 'S':
                    type = 2;
                    break;  
                default:
                    type = 3;   
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
                this->type =0;
                break;
            case 'M':
                this->type = 1;
                break;
            case 'N':
                this->type = 2;
                break;
            case 'S':
                this->type = 3;
                break;
            }
        }
        void setPosition(int x, int y){
            std::tuple<int, int> posNew = {x,y};
            this->position = posNew;
        }
};

#endif