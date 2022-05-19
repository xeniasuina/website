#include "tree_list2_0.h"
#include <cstring>

void tree_list_add(tree_list2& list, char* name, const double value) {
	tree_list2_elem* new_el = new tree_list2_elem;
	strcpy_s(new_el->name, strlen(name) + 1, name);
	new_el->mid = value;

	if (list.count == 0) {
		list.first = list.last = new_el;
	}
	else {
		if (new_el->mid >= list.first->mid) {
			list.first->prev = new_el;
			new_el->next = list.first;
			list.first = new_el;
		}
		else if (new_el->mid <= list.last->mid) {
			list.last->next = new_el;
			new_el->prev = list.last;
			list.last = new_el;
		}
		else {
			tree_list2_elem* curr = list.first;
			while (curr->mid > new_el->mid) {
				curr = curr->next;
			}
			new_el->next = curr;
			new_el->prev = curr->prev;
			curr->prev = new_el;
			if (new_el->prev) new_el->prev->next = new_el;
		}
	}

	list.count += 1;
}

void _tree_list_add(tree_list2& list, char* name, const double value) {
	tree_list2_elem* new_el = new tree_list2_elem;
	strcpy_s(new_el->name, strlen(name) + 1, name);
	new_el->mid = value;

	if (list.count == 0) {
		list.first = list.last = new_el;
	}
	else {
		if (strcmp(new_el->name, list.first->name) < 0) {
			list.first->prev = new_el;
			new_el->next = list.first;
			list.first = new_el;
		}
		else if (strcmp(new_el->name, list.last->name) > 0) {
			list.last->next = new_el;
			new_el->prev = list.last;
			list.last = new_el;
		}
		else {
			tree_list2_elem* curr = list.first;
			while (strcmp(new_el->name, curr->name) > 0) {
				curr = curr->next;
			}
			new_el->next = curr;
			new_el->prev = curr->prev;
			curr->prev = new_el;
			if (new_el->prev) new_el->prev->next = new_el;
		}
	}

	list.count += 1;
}

void tree_list_clear(tree_list2& list)
{
	tree_list2_elem* curr;
	int i = 1;
	while (i < list.count) {
		curr = list.first;
		list.first = list.first->next;
		delete[] curr->name;
		delete curr;
		i += 1;
	}
	list.last = nullptr;
	list.count = 0;
}