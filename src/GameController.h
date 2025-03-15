#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Map.h"
#include "Player.h"

class GameController {
    private:
        Map GAME_MAP;
        Player PROTAG;
        void render() const;
        
    public:
        GameController(int map_size, const std::string& player_name) 
            : GAME_MAP(map_size), PROTAG(player_name, 0, 0) {}
        void flow();
};

#endif