
#include "interface.h"
#include <string>
#include <optional>

 
// UCT Node Methods



Node::Node(Move move, Node* parent_inp){
    this->move = move;
    this->parent = parent_inp;
    this->Q = 0;
    this->N = 0;
    this->N_RAVE = 0;
    this->Q_RAVE = 0;
}


void Node::add_children(vector<Node*> list_of_children) {
    for (Node* item : list_of_children) {
        children.push_back(item);
    }
}


double Node::value(const float EXPLORE_CONST) {
    /* Returns the UCT value of node in MCTS algorithm*/


    if (N == 0) return INFINITY;
    else {
        double val = Q / N;
        printf("parent N: %d", parent->N);
        double explore = sqrt(log10(static_cast<double>(parent->N) / N));
        return val + (double)(EXPLORE_CONST * explore);
    }
}

Node* Node::find_child(Move move) {
    /*  Returns the child which constructed for input move.
            
    */
    
    // How to return either value, or NULL in return https://stackoverflow.com/a/2639268/6118987
    // 
    for (auto i = 0; i != children.max_size(); ++i) {
        printf("move: (%d , %d) \n", children.at(i)->move.x, children.at(i)->move.y);
        if (children.at(i)->move.x == move.x && children.at(i)->move.y == move.y) {
            return children.at(i);
        }
    }
    return nullptr;
}

