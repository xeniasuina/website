#include "tree.h"
#include "tree_queue.h"
#include "tree_struct.h"
#include <string.h>

bool _add_to_tree(tree_node*& root, char* name , double middle);

bool _add_to_tree_by_name(tree_node*& root, char* name, double middle);
void _drop_tree(tree_node*& tree_node);

int _get_height(tree_node* n);
void _wide_traverse(tree_queue& q, tree_node*& root, bool include_empty);


void add_to_tree(tree& tree, char* name , double middle)
{
	if (_add_to_tree(tree.root, name , middle))
		tree.elem_count++;
}

void add_to_tree_by_name(tree& tree, char* name, double middle) {
	if (_add_to_tree_by_name(tree.root, name, middle)) tree.elem_count += 1;
}

void drop_tree(tree& tree)
{
	_drop_tree(tree.root);
	tree.elem_count = 0;
}

bool _add_to_tree(tree_node*& root, char* name ,double middle)
{
	if (root)
	{
		if (strcmp(root->name, name) == 0) 
		{
			root->count++;
			return false;
		}
		auto& branch = middle < root->mid ? root->left : root->right;
		bool r = _add_to_tree(branch, name, middle);
		if (r) _get_height(root);
		return r;
	}
	tree_node* newnode = new tree_node;
	newnode->mid = middle;
	strcpy_s(newnode->name, strlen(name) + 1, name);
	root = newnode;
	return true;
}

bool _add_to_tree_by_name(tree_node*& root, char* name, double middle) {
	if (root)
	{
		if (strcmp(root->name, name) == 0)
		{
			root->count++;
			return false;
		}
		auto choose = strcmp(root->name, name);
		auto& branch = choose > 0 ? root->left : root->right;
		bool r = _add_to_tree_by_name(branch, name, middle);
		if (r) _get_height(root);
		return r;
	}
	tree_node* newnode = new tree_node;
	newnode->mid = middle;
	strcpy_s(newnode->name, strlen(name) + 1, name);
	root = newnode;
	return true;
}

inline void _del(tree_node*& root)
{
	//Удаление элементов узла дерева
	//....
	//Удаление узла
	delete[] root->name;
	delete root;
	root = nullptr;
}

void _drop_tree(tree_node*& root)
{
	if (root)
	{
		_drop_tree(root->left);
		_drop_tree(root->right);
		_del(root);
	}
}


int _get_height(tree_node* n) {
	if (!n) return 0;
	auto lh = n->left ? n->left->height : 0;
	auto rh = n->right ? n->right->height : 0;
	return n->height = 1 + (lh > rh ? lh : rh);
}

tree_queue wide_traverse(tree t, bool include_empty) {
	tree_queue q; 
	_wide_traverse(q, t.root, include_empty);
	return q;
}

void _wide_traverse(tree_queue& queue, tree_node*& r, bool include_empty) {
	if (!r) return;
	enqueue(queue, r);
	auto q = queue.head;
	const auto cnt = 1 << (r->height - 1);
	for (int i = 1; i < cnt; i += 1) {
		auto ln = q->tree_node ? q->tree_node->left : nullptr; 
		auto rn = q->tree_node ? q->tree_node->right : nullptr;
		if (ln || include_empty) enqueue(queue, ln); 
		if (rn || include_empty) enqueue(queue, rn); 
		q = q->next;
	}
}