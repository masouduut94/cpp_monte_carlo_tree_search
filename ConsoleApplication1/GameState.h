#pragma once
#include <vector>
#include "Move.h"

#pragma once
class GameState {
    /*
    Stores information representing the current state of a game of hex, namely
    the boardand the current turn.Also provides functions for playing game.
    */
private:
    int size;
    int turn;
    std::vector<std::vector<int>> board;
    int white_played;
    int black_played;
    //UnionFind white_groups;
    //UnionFind black_groups;

public:
    GameState(int size);
    void set_size(int inp_size) { size = inp_size; }
    int get_size() { return size; }

    void set_turn(int turn);
    int get_turn() { return this->turn; }

    void set_board(int inp_size);
    std::vector<std::vector<int>> get_board() { return this->board; }

    void play(Move move);
    void place_white(Move move);
    void place_black(Move move);
    std::vector<Move> get_moves();
    std::string print_board();
    std::vector<Move> neighbors(Move move);

};

