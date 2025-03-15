#include "Player.h"

void Player::setPosition(int newX, int newY){
    PLAYER_POSITION.x = newX;
    PLAYER_POSITION.y = newY;
}

std::string Player::getName() const {
    return PLAYER_NAME;
}

GameUtils::Position2D Player::getPosition() const {
    return PLAYER_POSITION;
}

void Player::movePlayer(char command, const Map& map){

    int currX = PLAYER_POSITION.x;
    int currY = PLAYER_POSITION.y;

    int newX = currX;
    int newY = currY;

    int currMapSize = map.getMapSize();

    switch (command) {
        case 'w':
            if (currY>0) newY = currY-1;
            break;

        case 'a':
            if (currX>0) newX = currX-1;
            break;

        case 's':
            if (currY<currMapSize-1) newY = currY+1;
            break;

        case 'd':
            if (currX<currMapSize-1) newX = currX+1;
            break;
    }

    setPosition(newX, newY);
}