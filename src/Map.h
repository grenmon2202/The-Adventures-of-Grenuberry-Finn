#ifndef MAP_H
#define MAP_H

class Map {
    private:
        int MAP_SIZE;
        char **MAP_GRID;
        int PLAYER_X;
        int PLAYER_Y;
    
    public:
        Map(int size);
        ~Map();
        void render() const;
        void movePlayer(char input);
};

#endif