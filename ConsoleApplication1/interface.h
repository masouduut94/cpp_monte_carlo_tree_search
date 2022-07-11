#include <math.h>
#include <vector>
#include <unordered_map>
#include <optional>


using namespace std;


struct GameMeta {
    const unordered_map<string, int> PLAYERS = {
            {"none",  0},
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


    class Node {
    private:
	    Move move;
	    int Q = 0;
	    int N = 0;
	    int N_RAVE = 0;
	    int Q_RAVE = 0;
        int OUTCOME = GameMeta().GAME_ON;
	    Node* parent;
	    std::vector <Node*> children;

    public:
	    Node(Move move, Node* parent = NULL);
	    double value(const float EXPLORE_CONST);
	    void add_children(vector<Node*>);
	    void add_win() { N++; Q++; }
	    void add_loss() { N++; }
	    void add_rave_win() { N_RAVE++; Q_RAVE++; }
	    void add_rave_loss() { N_RAVE++; Q_RAVE--; }
	    Move get_move() { return move; }
        Node* find_child(Move move);
    };


    class UnionFind {

    };

    class GameState {
        /*
        Stores information representing the current state of a game of hex, namely
        the boardand the current turn.Also provides functions for playing game.
        */
    private:
        int size;
        int turn;
        int board[10][10];
        int white_played;
        int black_played;
        UnionFind white_groups;
        UnionFind black_groups;

    public:
        void play(Move move);
        void place_white(Move move);
        void place_black(Move move);
        int get_turn() { return turn; }
        int get_moves();



    };
