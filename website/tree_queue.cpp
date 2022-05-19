#include "tree_queue.h"

void enqueue(tree_queue& queue, tree_node* tree_node)
{
	tree_elem* newel = new tree_elem;
	newel->tree_node = tree_node;
	if (!queue.tail)
	{
		queue.head = queue.tail = newel;
	} else
	{
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.size++;
}

bool dequeue(tree_queue& queue, tree_node*& tree_node)
{
	if (!queue.head)
		return false;
	tree_node = queue.head->tree_node;
	tree_elem* rem = queue.head;
	queue.head = queue.head->next;
	delete rem;
	if (!queue.head) queue.tail = nullptr;
	queue.size--;
	return true;
}

void clear(tree_queue& queue)
{
	while (queue.head)
	{
		tree_elem* rem = queue.head;
		queue.head = queue.head->next;
		delete rem;
	}
	queue.size = 0;
	queue.tail = nullptr;
}
