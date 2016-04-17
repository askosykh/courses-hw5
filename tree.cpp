#include "tree.h"
#include <iostream>


Tree::~Tree() {

    delete root;
}

Tree::Tree(const Tree& src_tree) {

    Node *src_root = src_tree.root;
    root = new Node(*src_root); 
}

Tree::Tree(): root(0) {}

void Tree::add(int value) {

    if (!root) {
        root = new Node(value);
        return;
    }

    Node* node = root;

    while (true) {
        if (node->go_right(value)) {
            if (node->has_right()) {
                node = node->get_right();
            } else {
                node->set_right(value);
                return;
            }
        } else if (node->go_left(value)) {
            if (node->has_left()) {
                node = node->get_left();
            } else {
                node->set_left(value);
                return;
            }
        } else {
            node->incr_count();
            return;
        }
    }
}


void Tree::print_all() {

    if ( !root )
        return;
    root->print_left_nodes();
    root->print_current();
    root->print_right_nodes();
    std::cout << '\n';
}

void Tree::print_leaves() {

    if( !root )
        return;
    root->print_leaves();
    std::cout << '\n';
}


Node* Tree::search(int value) {

    if( !root )
        return 0;
    Node* node = root;
    while (true) {
        if (node->go_right(value)) {
            if (node->has_right()) {
                node = node->get_right();
            } else {
                return 0;
            }
        } else if (node->go_left(value)) {
            if (node->has_left()) {
                node = node->get_left();
            } else {
                return 0;
            }
        } else {
            return node;
        }
    }
}

