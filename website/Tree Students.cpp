#include <iostream>
#include "utility.h"
#include "cgi.h"
#include "tree.h"
#include <cstring>
#include "tree_list2_0.h"
#include "tree_queue.h"
using namespace std;

void create_list(tree_list2& list) {
	ifstream f("template/data3.txt");
	char* line = new char[90];
	char* name = new char[80];
	char* middle = new char[10];
	bool sort_by_name = false;
	char* data = new char[128];
	char* pick = new char[10];
	get_form_data(data);
	get_param_value(pick, "choose", data);
	if (strcmp(pick, "") != 0) {
		if (strcmp(pick, "true") == 0) {
			sort_by_name = false;
		}
		else {
			sort_by_name = true;
		}
	}
	if (f.is_open()) {
		while (!f.eof()) {
			f.getline(line, 256);
			if (strcmp(line, "") == 0) break;
			char* tmp = _strdup(line);
			strtok_s(tmp, " ", &middle);
			name = tmp;
			if (!sort_by_name) {
				tree_list_add(list, name, make_double(middle));
			}
			else {
				_tree_list_add(list, name, make_double(middle));
			}
			delete[] tmp;
		}
		f.close();
	}
	delete[] line;
}

void create_tree(tree& t, bool sort_by_name) {
	ifstream f("template/data3.txt");
	char* line = new char[90];
	char* name = new char[80];
	char* middle = new char[10];
	if (f.is_open()) {
		while (!f.eof()) {
			f.getline(line, 256);
			if (strcmp(line, "") == 0) break;
			char* tmp = _strdup(line);
			strtok_s(tmp, " ", &middle);
			name = tmp;
			if (!sort_by_name) {
				add_to_tree(t, name,make_double(middle));
			}
			else {
				add_to_tree_by_name(t, name, make_double(middle));
			}
		}
	}
}

void show_tree_as_tree(tree t) {
	auto tq = wide_traverse(t, true);
	auto height = t.root->height;
	auto cell_in_row = (1 << height) - 1;
	cout << "<table class='tree-table'>\n";
	for (int i = 0; i < height; i++) {
		cout << "<tr class='tree-row'>\n";
		auto cnt = 0;
		auto empt_cells = (1 << (height - i - 1)) - 1;
		do {
			for (int j = 0; j < empt_cells; j++) {
				cout << "<td class='tree-empty-cell'>&nbsp;</td>";
				cnt++;
			}
			tree_node* n;
			dequeue(tq, n);
			cout << "<td class='tree-cell'>";
			if (n) cout << n->name << " " << n->mid;
			else cout << "-";
			cout << "</td>";
			cnt++;
			for (int j = 0; j < empt_cells; j++) {
				cout << "<td class='tree-empty-cell'>&nbsp;</td>";
				cnt++;
			}
			if (cnt < cell_in_row) {
				cout << "<td>&nbsp;</td>";
				cnt++;
			}
			else break;
		} while (true);
		cout << "</tr>\n";

	}
	cout << "</table>\n";
}

void treaeae() {
	tree tree;
	bool sort_by_name = false;
	char* data = new char[128];
	char* pick = new char[10];
	get_form_data(data);
	//cin >> data;
	get_param_value(pick, "choose", data);
	if (strcmp(pick, "") != 0) {
		if (strcmp(pick, "true") == 0) {
			sort_by_name = false;
		}
		else {
			sort_by_name = true;
		}
	}
	if (strcmp(data, "") == 0) {
		delete[] data;
		delete[] pick;
		return;
	}
	create_tree(tree, sort_by_name);
	show_tree_as_tree(tree);
	drop_tree(tree);
	delete[] data;
	delete[] pick;
}

void show_list(tree_list2 list) {
	if (list.count == 0) {
		cout << "<h2>List is empty!</h2>";
	}
	else {
		int i = 0;
		tree_list2_elem* curr = list.first;
		while (curr != list.last) {
			cout << curr->name << " " << curr->mid << ", ";
			curr = curr->next;
		}
		cout << list.last->name << " " << list.last->mid;
	}
}

void show_ranged_list(tree_list2 list) {
	double bottom_border = 0;
	double upper_border = 5;
	char* data = new char[128];
	char* up = new char[10];
	char* bottom = new char[10];
	get_form_data(data);
	//cin >> data;
	get_param_value(bottom, "bottom_border", data);
	get_param_value(up, "upper_border", data);
	if (strcmp(bottom, "") == 0 || strcmp(up, "") == 0) {
		delete[] data;
		delete[] bottom;
		delete[] up;
		return;
	}
	bottom_border = make_double(bottom);
	upper_border = make_double(up);
	tree_list2_elem* curr = list.first;
	while (curr->mid > upper_border) {
		curr = curr->next;
	}
	cout << "<h2>";
	while (curr->mid >= bottom_border) {
		cout << curr->name << " " << curr->mid << ", ";
		if (curr == list.last) break;
		curr = curr->next;
	}
	cout << "</h2>";
	delete[] data;
	delete[] bottom;
	delete[] up;
}


void tree_start() {
	tree_list2 list;
	create_list(list);
	cout << "<div class='tree'>";
	treaeae();
	cout << "</div>";
	cout << "<div class='casual-list'>";
	show_ranged_list(list);
	cout << "</div>";
	tree_list_clear(list);
}