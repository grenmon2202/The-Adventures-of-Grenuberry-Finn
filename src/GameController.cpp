#include "GameController.h"
#include "GameUtils.h"
#include <iostream>

void GameController::render() const {
    GameUtils::clearScreen();

    GAME_MAP.render(PROTAG.getPosition());

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i<GameUtils::getTerminalWidth(); i++){
        std::cout<<'-';
    }

    std::cout << std::endl;
}

void GameController::flow(){
    render();

    char command;
    std::cin >> command;

    PROTAG.movePlayer(command, GAME_MAP);
}