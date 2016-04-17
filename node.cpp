#include "node.h"
#include <iostream>


Node::Node(int value): data(value), count(1), left(0), right(0), parent(0) {}

Node::~Node() {
    
    if (left)
        delete left;

    if (right)
        delete right;
    
    if (parent) {
        if( parent->go_left(data) )
            parent->pop_left();
        else
            parent->pop_right();
    }
}

Node::Node(const Node& src_node) {

    data = src_node.data;
    count = src_node.count;
    if( src_node.left ) {
        Node *new_left = new Node(*(src_node.left));
        set_left(new_left);
    }
    if( src_node.right ) {
        Node *new_right = new Node(*(src_node.right));
        set_right(new_right);
    }
}


int Node::get_data() {

    return data;
}

int Node::get_count() {
    
    return count;
}

Node* Node::get_right() {

    return right;
}

Node* Node::get_left() {
    
    return left;
}

Node* Node::get_parent() {

    return parent;
}

void Node::reset_parent() {

    parent = 0;
}

bool Node::set_parent(Node* node) {

    if( parent )
        return false;
    parent = node;
    return true;
}

bool Node::set_right(int value) {
    
    if (right)
        return false;
    right = new Node(value);
    right->set_parent(this);
    return true;
}

bool Node::set_right(Node* node) {
    
    if (right)
        return false;
    right = node;
    right->set_parent(this);
    return true;
}

bool Node::set_left(int value) {
    
    if (left)
        return false;
    left = new Node(value);
    left->set_parent(this);
    return true;
}

bool Node::set_left(Node* node) {
    
    if (left)
        return false;
    left = node;
    left->set_parent(this);
    return true;
}

void Node::incr_count() {
    ++count;
}

void Node::decr_count() {
    --count;
}

bool Node::go_right(int value) {

    return value > data;
}

bool Node::go_left(int value) {
    
    return value < data;
}

bool  Node::has_right() {

    return right;
}

bool Node::has_left() {

    return left;
}

bool Node::has_parent() {

    return parent;
}

Node* Node::pop_right() {

    Node* tmp = right;
    right = 0;
    tmp->reset_parent();
    return tmp;
}

Node* Node::pop_left() {

    Node* tmp = left;
    left = 0;
    tmp->reset_parent();
    return tmp;
}

void Node::print_current() {
    for( size_t i = 0; i < count; ++i )
        std::cout << get_data() << ' ';
}

void Node::print_left_nodes() {

    if( !has_left() )
        return;
    left->print_left_nodes();
    left->print_current();
    left->print_right_nodes();
}

void Node::print_right_nodes() {

    if( !has_right() )
        return;
    right->print_left_nodes();
    right->print_current();
    right->print_right_nodes();
}

void Node::print_leaves() {

    if( !has_left() && !has_right() ) {
        std::cout << get_data() << ' ';
        return;
    }
    if( has_left() )
        left->print_leaves();
    if( has_right() )
        right->print_leaves();
}
