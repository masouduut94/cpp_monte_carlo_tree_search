#include <math.h>
#include <map>
#include<string>

struct GameMeta {
    std::map<std::string, int> PLAYERS = {
        {"none",  0},
        {"white", 1},
        {"black", 2}
    };

    std::map<std::string, int> TURN = {
        {"white", 1},
        {"black", 2}
    };

    float INF = INFINITY;
    int GAME_OVER = -1;
    int GAME_ON = 1;
    const int EDGE1 = 1;
    const int EDGE2 = 2;
    const int NEIGHBOR_PATTERNS[6][2] = {
            {-1, 0},
            {0,  -1},
            {-1, 1},
            {0,  1},
            {1,  0},
            {1,  -1}
    };
};


struct Move
{
    int x;
    int y;
};