#include "Map.h"
#include "GameUtils.h"
#include <iostream>
#include <cstring>

Map::Map(int size) {

    MAP_SIZE = size;
    MAP_GRID = new char*[size];

    for (int i = 0; i < MAP_SIZE; i++){
        MAP_GRID[i] = new char[size];
        memset(MAP_GRID[i], '.', size);
    }

    PLAYER_X = 0;
    PLAYER_Y = 0;
}

Map::~Map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        delete[] MAP_GRID[i];
    }
    delete[] MAP_GRID;
}

void Map::render() const {
    
    // ----- CLEAR SCREEN BLOCK -----
    // clearing screen using relevant command for OS
    #ifdef _WIN32
    system("cls");

    #else
    system("clear");

    #endif

    // ----- RENDER FRESH MAP -----
    for (int i = 0; i<MAP_SIZE; i++){
        for (int j = 0; j<MAP_SIZE; j++){
            if (i == PLAYER_Y && j == PLAYER_X){
                std::cout << "P" << " ";
            }
            else {
                std::cout << MAP_GRID[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // ----- RENDER DIVIDER -----
    for (int i = 0; i<GameUtils::getTerminalWidth(); i++){
        std::cout << '-';
    }

    std::cout << std::endl;
}

void Map::movePlayer(char input) {
    switch (input) {
        case 'w':
            if (PLAYER_Y>0) PLAYER_Y--;
            break;

        case 'a':
            if (PLAYER_X>0) PLAYER_X--;
            break;

        case 's':
            if (PLAYER_Y<MAP_SIZE-1) PLAYER_Y++;
            break;

        case 'd':
            if (PLAYER_X<MAP_SIZE-1) PLAYER_X++;
            break;
    }
}