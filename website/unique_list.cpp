#include "pageloader.h"
#include "unique_list.h"
#include "cgi.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

void list1_add(list1& list, int val) {
	auto new_el = new l1_elem;
	new_el->a = val;
	if (!list.first) {
		list.first = new_el;
	}
	else {
		auto curr = list.first;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = new_el;
	}
	list.count += 1;
}

void list1_insert(list1& list, int val, int pos) {
	auto new_el = new l1_elem;
	new_el->a = val;

	if (list.first && pos > 0) {
		//указатель на текущий элемент
		l1_elem* curr = list.first;
		int p = 0;
		//проходим по элементам списка до элемента с позицией pos-1 либо до последнего
		while (p < pos - 1 && curr->next) {
			curr = curr->next;
			p += 1;
		}
		if (new_el->a == curr->a) return;
		//размещение нового элемента в списке
		new_el->next = curr->next;
		curr->next = new_el;
		//если pos больше чем колво элементов в списке, то элемент добавится на последнее место
	}
	else {
		new_el->next = list.first;
		list.first = new_el;
	}
}

bool list1_get(const list1 list, int& val, int pos) {
	if (!list.first || pos < 0) {
		cout << "Ошибочка" << endl;
		return false;
	}
	//Заводим щетчик
	int p = 0;
	l1_elem* curr = list.first;
	while (p < pos && curr) {
		curr = curr->next;
		p += 1;
	}
	if (curr) {
		val = curr->a;
		return true;
	}
	else return false;
}

bool list1_remove(list1& list, int pos) {
	if (!list.first || pos < 0) {
		std::cout << "Ошибка" << std::endl;
		return false;
	}
	//Удаление первого элемента (нулевого)
	if (pos == 0) {
		l1_elem* del = list.first;
		list.first = list.first->next;
		delete[] del;
		return true;
	}
	//Если удаляем элементы из середины
	int p = 0;
	l1_elem* curr = list.first;
	while (p < pos - 1 && curr->next) {
		curr = curr->next;
		p += 1;
	}
	if (curr->next) {
		l1_elem* del = curr->next;
		curr->next = del->next;
		delete[] del;
		return true;
	}
	return false;
}

void list1_clear(list1& list) {
	while (list.first) {
		l1_elem* del = list.first;
		list.first = list.first->next;
		delete[] del;
	}
}


void fill_list(list1& list) {
    ifstream f;
    f.open("/template/list_data.txt");
    if (f.is_open()) {
        int i = 0;
        int x;
        while (f >> x) {
            list1_insert(list, x, i);
            i += 1;
        }
        f.close();
    }
}

void save_list_to_file(list1 list) {
    ofstream f;
    f.open("template/list_data.txt");
    if (f.is_open()) {
        l1_elem* curr = list.first;
        if (!curr) {
            f.close();
            return;
        }
        while (curr) {
            f << curr->a << (curr->next ? " " : "");
            curr = curr->next;
        }
        f.close();
    }
}

void show_list(list1 list) {
	cout << "<div class='unique_list'>";
	l1_elem* curr = list.first;
	if (list.count == 0 || !curr) {
		cout << "<div class='error'><h2> List is empty </h2></div>";
		cout << "</div>";
		return;
	}
	while (curr) {
		cout << curr->a << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << "</div>";
}


void unique_list() {
    /*Написать программу, в которой реализовать функции добавления и
    вставки элементов в односвязный список, так, чтобы
    в списке оставались только уникальные значения */
    char* data = new char[100];
    get_form_data(data);
    char* value = new char[20];
    char* position = new char[20];
    get_param_value(value, "value", data);
    get_param_value(position, "position", data);
    list1 list;
    fill_list(list);
    try {
        int val = stoi(value);
        int pos = stoi(position);

        list1_insert(list, val, pos);

    }
    catch (exception ex) { }

    show_list(list);
    save_list_to_file(list);
    list1_clear(list);

    delete[] data;
    delete[] position;
    delete[] value;
}