#pragma once
#include "tree_struct.h"

void enqueue(tree_queue& queue, tree_node* tree_node);

bool dequeue(tree_queue& queue, tree_node*& tree_node);

void clear(tree_queue& queue);
