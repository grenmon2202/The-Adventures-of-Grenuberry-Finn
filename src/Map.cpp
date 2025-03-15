#include "Map.h"
#include <iostream>
#include <cstring>

Map::Map(int size) {

    MAP_SIZE = size;
    MAP_GRID = new char*[size];

    for (int i = 0; i < MAP_SIZE; i++){
        MAP_GRID[i] = new char[size];
        memset(MAP_GRID[i], '.', size);
    }
}

Map::~Map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        delete[] MAP_GRID[i];
    }
    delete[] MAP_GRID;
}

void Map::render(const GameUtils::Position2D& playerPos) const {

    // ----- RENDER FRESH MAP -----
    for (int i = 0; i<MAP_SIZE; i++){
        for (int j = 0; j<MAP_SIZE; j++){
            if (i == playerPos.y && j == playerPos.x){
                std::cout << "P" << " ";
            }
            else {
                std::cout << MAP_GRID[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int Map::getMapSize() const {
    return MAP_SIZE;
}