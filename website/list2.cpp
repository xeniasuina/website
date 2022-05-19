#include "list2.h"
#include <string>
using namespace std;

void add(list2& list, char data[]) {
	l2_elem* new_el = new l2_elem;
	size_t length = sizeof(new_el->elems) / sizeof(new_el->elems[0]);
	for (int i = 0; i < length; i += 1) {
		new_el->elems[i] = data[i];
	}
	try {
		new_el->value = stoi(data);
	}
	catch (exception ex) {
		string res = "";
		int i = 0;
		while (data[i] != 'X') {
			res += data[i];
		}
		new_el->value = stoi(data);
	}

	if (list.count == 0) {
		list.first = list.last = new_el;
	}
	else {
		l2_elem* curr = list.first;
		while (curr) {
			curr = curr->next;
		}
		new_el->prev = curr;
		curr->next = new_el;
	}
	
	list.count += 1;
}

bool remove(list2& list, int pos)
{
	if (pos < 0 || pos >= list.count) return false;		
	list.count -= 1;
	if (pos == 0) {
		auto del = list.first;
		list.first = list.first->next;
		if (list.first) {
			list.first->prev = nullptr;
		}
		delete[] del;
		return true;
	}
	if (pos == list.count) {
		auto del = list.last;
		list.last = list.last->prev;
		list.last->next = nullptr;
		delete[] del;
		return true;
	}
	auto frw = (pos <= list.count / 2);
	l2_elem* curr;
	int p = 1;
	if (frw) {
		curr = list.first->next;
	}
	else {
		curr = list.last->prev;
		pos = list.count - pos;
	}
	while (p < pos) {
		curr = frw ? curr->next : curr->prev;
		p += 1;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
	return true;
}

const char* get(list2 list, int pos)
{
	if (pos < 0 || pos >= list.count || !list.first) return nullptr;
	
	if (!pos) return list.first->elems;

	if (pos == list.count - 1) return list.last->elems;

	int p = 1;
	auto fwd = (pos <= list.count / 2);
	l2_elem* curr;
	if (fwd) {
		curr = list.first->next;
	}
	else {
		curr = list.last->prev;
		pos = list.count - pos - 1;
	}
	while (curr && p < pos) {
		p++;
		curr = fwd ? curr->next : curr->prev;
	}
	return curr->elems;
}

void clear(list2& list)
{
	l2_elem* curr;
	while (list.first) {
		curr = list.first;
		list.first = list.first->next;
		delete curr;
	}
	list.last = nullptr;
	list.count = 0;
}



