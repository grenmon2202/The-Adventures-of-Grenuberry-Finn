#include "Map.h"
#include <iostream>

int main() {
    Map gameMap(20);
    char command;

    while (true) {
        gameMap.render();
        std::cin >> command;
        gameMap.movePlayer(command);
    }

    return 0;
}