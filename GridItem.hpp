#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP
#include <iostream>
#include <utility>

static int GridItemCount = 0;

class GridItem{
    public:
        int x;
        int y;
        int width;
        int height;
        std::pair<int, int> coordinates;
        GridItem(int x, int y, int width, int height){
            this->x = x;
            this->y = y;
            coordinates = std::make_pair(x,y);
            this->width = width;
            this->height = height;
            GridItemCount++;
        }
        GridItem(){
            this->x = 0;
            this->y = 0;
            coordinates = std::make_pair(x,y);
            this->width = 0;
            this->height = 0;
            GridItemCount++;
        }
        void setCoordinates(int x, int y){
            coordinates = std::make_pair(x,y);
        }
        std::pair<int, int> getCoordinates(){
            return coordinates;
        }
        int getGridWidth(){
            return width;
        }
        int getGridHeight(){
            return height;
        }
        static int getActiveGridItemCount(){
            return GridItemCount;
        }
        virtual ~GridItem(){
            GridItemCount--;
        }
};

#endif