#pragma once

void unique_list();

struct l1_elem {
	int a;
	l1_elem* next = nullptr; //Указатель на следующий элемент списка
};

/// <summary>
/// Структура для хранения указателя на начало односвязного списка
/// </summary>
struct list1 {
	l1_elem* first = nullptr;
	int count = 0;
};

/// <summary>
///	Функция добавления элемента в список
/// </summary>
/// <param name="list">Список, куда нужно добавить новое значение</param>
/// <param name="val">Добавляемое в список значение</param>
void list1_add(list1& list, int val);

/// <summary>
/// Функция вставки элемента в список на определенную позицию
/// </summary>
/// <param name="list">Список, куда нужно вставить элемент</param>
/// <param name="val">Значение элемента</param>
/// <param name="pos">Позиция, на которую требуется вставить элемент</param>
void list1_insert(list1& list, int val, int pos);

/// <summary>
/// Получеие значения элемента списка, расположенного в позиции pos
/// </summary>
/// <param name="list">Сам список</param>
/// <param name="val">Полученное значение</param>
/// <param name="pos">Позиция</param>
/// <returns>
/// true - если значение успешно получено
/// false -  если была указана неверная позиция
/// </returns>
bool list1_get(const list1 list, int& val, int pos);
/// <summary>
/// Функция удаляет элемент списка, расположеный на указанной позиции
/// </summary>
/// <param name="list">Список</param>
/// <param name="pos">Позиция, с которой нужно удалить</param>
/// <returns>
/// true - успешно удалено
/// false - позиция неверная
/// </returns>
bool list1_remove(list1& list, int pos);
/// <summary>
/// Функция, которая удаляет все элементы списка из памяти
/// </summary>
/// <param name="list">Список</param>
void list1_clear(list1& list);
