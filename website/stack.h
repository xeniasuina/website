#pragma once

/// <summary>
/// Структура для хранения элементов стека
/// </summary>

struct stackElem
{
	/// <summary>
	/// Сохраняемое в стеке значение
	/// </summary>
	int pos = 0;
	char c;
	/// <summary>
	/// Указатель на следующий элемент в стеке
	/// </summary>
	stackElem* next = nullptr;
};

/// <summary>
/// Добавление элемента в стек
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Размещаемый в стеке элемент</param>
void push(stackElem*& stack, char x, const int pos);

/// <summary>
/// Удаляет из стека элемент и возвращает его значение
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемый элемент</param>
/// <returns>
/// true, если удалось изъять из стека элемент и
/// false в противном случае
/// </returns>
bool pop(stackElem*& stack, char& x);

/// <summary>
/// Возвращает значение элемента с вершины стека, но оставляет сам элемент в стеке
/// </summary>
/// <param name="stack">Указатель на вершину стека</param>
/// <param name="x">Возвращаемое значение элемента с вершины стека</param>
/// <returns>
/// true, если удалось получить из стека элемент и
/// false в противном случае
/// </returns>
bool peek(const stackElem* stack, int& pos, char& br);

/// <summary>
/// Функция удаления стека из памяти 
/// </summary>
/// <param name="stack">Указатель на вершины удаляемого стека</param>
void clear(stackElem*& stack);

