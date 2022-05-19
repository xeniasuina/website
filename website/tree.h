#pragma once
#include "tree_struct.h"
#include "Queue.h"

void tree_start();

void add_to_tree(tree& tree, char* name, double mid);
void add_to_tree_by_name(tree& tree, char* name, double middle);
void drop_tree(tree& tree);

tree_queue wide_traverse(tree tree, bool include_empty = true);