#pragma once
#include "utils.h"

class  Move {
private:
    char x;
    int y;

public:
    Move() {};
    Move(int x_inp, int y_inp);
    void setX(int x_inp);
    char getX();
    int getY();
};


