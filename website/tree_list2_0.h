#pragma once

#include <string>

struct tree_list2_elem {
	char* name = new char[80];
	double mid;

	tree_list2_elem* next = nullptr;
	tree_list2_elem* prev = nullptr;
};

struct tree_list2 {
	tree_list2_elem* first = nullptr;
	tree_list2_elem* last = nullptr;
	tree_list2_elem* barrier = nullptr;
	int count = 0;
};

void tree_list_add(tree_list2& list, char* name, const double value);

void _tree_list_add(tree_list2& list, char* name, const double value);

void tree_list_clear(tree_list2& list);