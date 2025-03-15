#include "GameController.h"
#include "Map.h"
#include "Player.h"
#include "GameUtils.h"

int main() {
    GameController game(20, "Grenmon");

    while (true) {
        game.flow();
    }

    return 0;
}