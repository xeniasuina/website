#pragma once
#include <cstddef>
struct tree_node
{
	char* name = new char[80];
	double mid;
	int count = 1;
	int height = 1;
	tree_node* left = nullptr;
	tree_node* right = nullptr;
};

struct tree
{
	tree_node* root = nullptr;
	size_t elem_count = 0;
};

struct tree_elem
{
	tree_node* tree_node;
	tree_elem* next = nullptr;
};

struct tree_queue
{
	tree_elem* head = nullptr;
	tree_elem* tail = nullptr;
	size_t size = 0;
};