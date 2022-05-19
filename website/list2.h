#pragma once

/// <summary>
/// Структура для хранения элементов списка
/// </summary>
struct l2_elem {
	char elems[9];
	int value;
	
	l2_elem* next = nullptr;
	l2_elem* prev = nullptr;
};

/// <summary>
/// Структура для обьединения указателей, определяющих двусвязный список
/// </summary>
struct list2 {
	/// <summary>
	/// Pervii element spiska
	/// </summary>
	l2_elem* first = nullptr;
	/// <summary>
	/// lastovii element spiska
	/// </summary>
	l2_elem* last = nullptr;

	/// <summary>
	/// chislo elementov v liste
	/// </summary>
	int count = 0;

};
/// <summary>
/// Funkciya dobavlenia elementa v spisok
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
void add(list2& list, char data[]);

bool remove(list2& list, int pos);

const char* get(list2 list, int pos);

void clear(list2& list);

