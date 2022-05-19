#include "list1.h"


void add(list1& list, int val) {
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

void insert(list1& list, int val, int pos){
	auto new_el = new l1_elem;
	new_el->a = val;
	
	if(list.first && pos > 0){
		//указатель на текущий элемент
		l1_elem* curr  = list.first;
		int p = 0;
		//проходим по элементам списка до элемента с позицией pos-1 либо до последнего
		while(p < pos - 1 && curr->next){
			curr = curr->next;
			p+=1;
		}
		if (new_el->a == curr->a) return;
		//размещение нового элемента в списке
		new_el->next = curr->next;
		curr->next = new_el;
		//если pos больше чем колво элементов в списке, то элемент добавится на последнее место
	} else{
		new_el->next = list.first;
		list.first = new_el;
	}
}

bool get(const list1 list, int& val, int pos){
	if(!list.first || pos < 0){
		std::cout << "Ошиб очка" << std::endl;
		return false;
	}
	//Заводим щетчик
	int p = 0;
	l1_elem* curr = list.first;
	while(p<pos && curr){
		curr = curr->next;
		p+=1;
	}
	if(curr){
		val = curr->a;
		return true;
	}else return false;
}

bool remove(list1& list, int pos){
	if(!list.first || pos < 0){
		std::cout << "Ошибка" << std::endl;
		return false;
	}
	//Удаление первого элемента (нулевого)
	if(pos == 0){
		l1_elem* del = list.first;
		list.first = list.first->next;
		delete[] del;
		return true;
	}
	//Если удаляем элементы из середины
	int p = 0;
	l1_elem* curr = list.first;
	while(p < pos-1 && curr->next){
		curr = curr->next;
		p+=1;
	}
	if(curr->next){
		l1_elem* del = curr->next;
		curr->next = del->next;
		delete[] del;
		return true;
	}
	return false;
}

void clear(list1& list){
	while(list.first){
		l1_elem* del = list.first;
		list.first=list.first->next;
		delete[] del;
	}
}






