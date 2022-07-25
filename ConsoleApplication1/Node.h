#include "utils.h"
#include <vector>


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
	void add_children(std::vector<Node*>);
	void add_win() { N++; Q++; }
	void add_loss() { N++; }
	void add_rave_win() { N_RAVE++; Q_RAVE++; }
	void add_rave_loss() { N_RAVE++; Q_RAVE--; }
	Move get_move() { return move; }
	Node* find_child(Move move);
};

