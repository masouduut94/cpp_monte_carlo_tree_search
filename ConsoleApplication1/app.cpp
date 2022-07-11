// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "interface.h"
//#include <random>

using namespace std;

char cell_char(int value) {
    unordered_map<int, char> mapper = {
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
    };
    return mapper[value];
}


int main()
{

    Move move = { 2, 4 };
    const float EXP = 0.21;
    Node *root = new Node(move, nullptr);

    double val = root->value(EXP);
    cout << val << endl;
    auto v = root->get_move();
    auto f = cell_char(v.x);

    printf("move = %c %d\n", f, v.y);

    vector<Node*> children;
    // Moves from (0, 2) to (20, 2);
    for (int i = 0; i <= 20; i++) {  
        Move move1 = { i,2 };
        //Node item = Node(move1, &root);
        Node *item = new Node(move1, root);
        item->add_win();
        children.emplace_back(item);
    }

    root->add_children(children);
    
    //Move a = {18, 2}; // move (18, 1) is selected to be evaluated.
    //Node* p = root->find_child(a);
    //children.clear();
     //Moves from (0, 10) to (20, 10) 
    /*for (int i = 0; i <= 10; i++) {
        Move move1 = { i*2,10 };
        Node* item = new Node(move1, p);
        root->add_win();
        item->add_win();
        item->add_win();
        item->add_loss();
        children.emplace_back(item);
    }

    val = p->value(1);
    printf("\n");
    printf("value is %f", val);*/



}

