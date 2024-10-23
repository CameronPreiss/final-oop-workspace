#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <cmath>
#include <iostream>
#include <tuple>

enum GameEntityType : char{
    ExplosionType = 0,
    MineType = 1,
    NoneType = 2,
    ShipType = 3
};

class GameEntity{
    private:
        std::tuple<int, int> position;
        GameEntityType type;
    public:
        GameEntity(int x, int y, char temp_type){
            position = std::make_tuple(x,y);
            switch (temp_type){
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
        std::tuple<int, int> getPos(){
            return position;
        }
        GameEntityType getType(){
            return type;
        }
        void setPos(int x_temp, int y_temp){
            position = std::make_tuple(x_temp, y_temp);
        }
        void setType(char temp_type){
            switch (temp_type){
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
        virtual ~GameEntity(){}
};

#endif