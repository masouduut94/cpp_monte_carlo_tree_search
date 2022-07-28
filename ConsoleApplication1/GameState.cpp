#include "GameState.h"

// ####################################### GameState Module...

GameState::GameState(int size) {
    this->set_size(size);
    this->set_turn(GameMeta().TURN["white"]);
    this->set_board(this->size);
    int white_played = 0;
    int black_played = 0;
    //UnionFind white_groups;
    //UnionFind black_groups;
}

void GameState::set_board(int inp_size) {
    this->set_size(inp_size);
    for (int i=0; i <= this->size; ++i) {
        std::vector<int> v1;
        for (int j=0; j <= inp_size; ++j) {
            v1.push_back(0);
        }
        this->board.push_back(v1);
    }
}

void GameState::set_turn(int turn_inp) {
    // manually changes the turn.
    turn = turn_inp;
}

void GameState::play(Move move) {
    // Plays the move based on game turn.
    if (this->turn == GameMeta().TURN["white"]) {
        this->place_white(move);
        this->set_turn(GameMeta().TURN["black"]);
    }
    else {
        this->place_black(move);
        this->set_turn(GameMeta().TURN["white"]);
    }
}

void GameState::place_white(Move move) {
    // Places the white stone on cell and changes the turn to black
    if (this->board[move.x][move.y] == GameMeta().PLAYERS["none"]) {
        this->board[move.x][move.y] = GameMeta().PLAYERS["white"];
        this->white_played += 1;
    }
    else {
        printf("The cell is occupied before.");
    }
    // TODO: Add White groups join later.
}

void GameState::place_black(Move move) {
    // Places a black stone on cell and changes the turn to white.
    if (this->board[move.x][move.y] == GameMeta().PLAYERS["none"]) {
        this->board[move.x][move.y] = GameMeta().PLAYERS["black"];
        this->white_played += 1;
    }
    else {
        printf("The cell is occupied before.");
    }
    // TODO: Add Black groups join later.
}

std::vector<Move> GameState::get_moves() {
    // Returns list of unoccupied cells.
    std::vector<Move> moves;
    for (int i = 0; i < this->board.max_size(); i++)
    {
        for (int j = 0; j < this->board.max_size(); j++)
        {
            if (this->board[i][j] == GameMeta().PLAYERS["none"])
            {
                Move move = { i, j };
                moves.push_back(move);
            }

        }
    }
    return moves;
}

std::string GameState::print_board() {
    // Prints a string of the board.
    // white player -> O (board left/right)  
    // black player -> @ (board up/down) 
    // No player -> .

    std::string board_map = "";
    std::string white = "O";
    std::string black = "@";
    std::string empty = ".";
    std::string ret = "\n";



    // https://github.com/kenjyoung/mopyhex/blob/763cc4f20472be131fa01ce9ba5052cb1ddf191c/gamestate.py#L127

    return "NOTHING";
}

std::vector<Move> GameState::neighbors(Move cell) {
    // Returns all the unoccupied cells around input cell.
    auto x = cell.x;
    auto y = cell.y;
    std::vector<Move> unoccupied_cells;
    for (auto item : GameMeta().NEIGHBOR_PATTERNS)
    {
        if ((0 <= item[0] + x < this->size) && (0 <= item[1] + y < this->size))  // TODO: Double-check if this comparison is working
        {
            Move move = { x + item[0], y + item[1] };
            unoccupied_cells.push_back(move);
        }
    }

    return unoccupied_cells;
}
