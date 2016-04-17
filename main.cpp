#include "node.h"
#include "tree.h"
#include <cstdio>
#include <cstdlib>


Tree* create_tree_from_file(FILE* file) {
    
    int value = 0;
    Tree* tree = new Tree();
    while (fscanf(file,"%d",&value) == 1) {
        tree->add(value);
    }
    return tree;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    Tree* tree = create_tree_from_file( f );
    fclose(f);
    tree->print_all();
    tree->print_leaves();
    delete tree;
    return 0;
}
