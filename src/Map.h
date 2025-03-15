#ifndef MAP_H
#define MAP_H

#include "GameUtils.h"

class Map {
    private:
        int MAP_SIZE;
        char **MAP_GRID;
    
    public:
        Map(int size);
        ~Map();
        void render(const GameUtils::Position2D& playerPos) const;  // renders the map on the terminal 
        int getMapSize() const;
};

#endif