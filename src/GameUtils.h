#ifndef GAME_UTILS_H
#define GAME_UTILS_H

namespace GameUtils {
    int getTerminalWidth();
    void clearScreen();
    
    struct Position2D {
        int x;
        int y;

        Position2D(int x = 0, int y = 0);

        // check for equality with another positon
        bool operator==(const Position2D& other) const;

        double distance(const Position2D& other) const;
    };
}

#endif