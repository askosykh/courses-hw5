#ifndef _NODE_H
#define _NODE_H

class Node;

class Node {

    private:

        // value of node
        int data;

        // ptr to left child
        Node* left;

        // ptr to right child
        Node* right;

        // ptr to parent
        Node* parent;

        // count of duplicated nodes
        int count;

    public:
        
        // constructors
        Node(int value);
        Node(const Node&);

        // destructor
        ~Node();

        // getters
        int get_data();     // get value of node
        int get_count();    // get count of duplicated nodes 
        Node* get_right();   // get ptr to left child
        Node* get_left();  // get ptr to right child
        Node* get_parent();

        // setters
        bool set_right(int value);  // sets the node with data
        bool set_right(Node* node); // sets the node to the right
        bool set_left(int value);
        bool set_left(Node* node);
        bool set_parent(Node*);
        void reset_parent();

        void incr_count();
        void decr_count();
        
        // check the node's position
        bool go_right(int value);
        bool go_left(int value);
        
        // check the existens of child
        bool has_right();
        bool has_left();
        bool has_parent();

        // get and delete
        Node* pop_right();
        Node* pop_left();
        void print_left_nodes();
        void print_right_nodes();
        void print_current();
        void print_leaves();
};

#endif // _NODE_H
