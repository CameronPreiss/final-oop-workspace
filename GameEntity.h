#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <iostream>
#include <cmath>
#include <tuple>

enum GameEntityType{
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
                    type = ExplosionType;
                    break;
                case 'M':
                    type = ExplosionType;
                    break;
                case 'S':
                    type = ExplosionType;
                    break;  
                default:
                    type = NoneType;   
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
};

#endif