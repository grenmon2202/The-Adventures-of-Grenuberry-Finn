#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "GameUtils.h"
#include "Map.h"

class Player {
    private:
        std::string PLAYER_NAME;
        GameUtils::Position2D PLAYER_POSITION;
        void setPosition(int newX, int newY);

    public:
        Player(const std::string& name, int startX = 0, int startY = 0)
            : PLAYER_NAME(name), PLAYER_POSITION(startX, startY) {}

        std::string getName() const;
        GameUtils::Position2D getPosition() const;

        void movePlayer(char command, const Map& map);
};

#endif