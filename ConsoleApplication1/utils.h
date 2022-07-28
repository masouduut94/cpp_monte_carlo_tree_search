#pragma once
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

    const unordered_map<int, char> mapper = {
        {0, 'A'},
        {1, 'B'},
        {2, 'C'},
        {3, 'D'},
        {4, 'E'},
        {5, 'F'},
        {6, 'G'},
        {7, 'H'},
        {8, 'I'},
        {9, 'J'},
        {10, 'K'},
        {11, 'L'},
        {12, 'M'},
        {13, 'N'},
        {14, 'O'},
        {15, 'P'},
        {16, 'Q'},
        {17, 'R'},
        {18, 'S'},
        {19, 'T'},
        {20, 'U'},
        {21, 'V'},
        {22, 'W'},
        {23, 'X'},
        {24, 'Y'},
        {25, 'Z'},
    };

};

struct Move
{
    int x;
    int y;

};



class Move1 {
private:
    char x;
    int y;

public:
    Move1(int x_inp, int y_inp) {
        setX(x_inp);
        y = y_inp;
    }
    void setX(int x_inp) {
        x = cell2char(x_inp)
    };

};


