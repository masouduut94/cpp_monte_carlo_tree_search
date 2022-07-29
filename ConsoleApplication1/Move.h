#pragma once
#include "utils.h"

class  Move {
private:
    char x;
    int y;

public:
    Move(int x_inp, int y_inp);
    void setX(int x_inp);
    char getX();
    int getY();
};

Move::Move(int x_inp, int y_inp) {
    int size = GameMeta().mapper.size();
        this->setX(x_inp);
        this->y = y_inp;
};

void Move:: setX(int x_inp)  {
    this->x = GameMeta().mapper[x_inp];
};

char Move::getX() {
    return this->x;
};

int Move::getY() {
    return this->y;
}
