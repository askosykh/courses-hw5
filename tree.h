#ifndef _TREE_H
#define _TREE_H
#include "node.h"

class Tree{

    private:
        Node* root;

    public:
        Tree();
        ~Tree();
        Tree(const Tree&);
        void add(int);
        void print_all();
        void print_leaves();
        Node* get_root();
        Node* search(int);


};
#endif // _TREE_H

