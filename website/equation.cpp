#include "equation.h"
#include "utility.h"
#include "cgi.h"
#include "pageloader.h"

void stack_push(stackElem*& top, char x, const int pos)
{
	//Создаем элемент стека (размещаем в памяти)
	stackElem* new_el = new stackElem;
	new_el->c = x;
	new_el->pos = pos;
	//Изменяем указатель на следующий элемент стека
	new_el->next = top;
	//Корректируем указатель на вершину стека
	top = new_el;
}

bool stack_pop(stackElem*& top, char& x)
{
	//Проверка стека на пустоту
	if (!top) return false;
	//Сохранение значения элемента стека
	x = top->c;
	//Сохранение указателя на текущую вершину во временной переменной
	stackElem* old_el = top;
	//Изменение вершины стека
	top = top->next;
	//Очищаем память из-под удаляемого элемента
	delete old_el;
	return true;
}

bool stack_peek(const stackElem* top, int& pos, char& br)
{
	//Проверка стека на пустоту
	if (!top) return false;
	//Сохранение значения элемента стека
	pos = top->pos;
	br = top->c;
	return true;
}

void stack_clear(stackElem*& top)
{
	char x;
	while (top) stack_pop(top, x);
}

void check_equation(const char* equation, stackElem*& top, char*& marks) {
    size_t sz = strlen(equation);
    for (int i = 0; i < sz; i += 1) {
        if (is_delimeter(equation[i])) continue;

        if (isdigit(equation[i]) || isalpha(equation[i]) || is_operand(equation[i])) continue;

        if (is_open_bracket(equation[i])) {
            stack_push(top, equation[i], i);
            continue;
        }
        if (is_closed_bracket(equation[i])) {
            char br, tmp;
            int pos;
            if (stack_peek(top, pos, br) && type_of_bracket(equation[i]) == br) stack_pop(top, tmp);
            else {
                stack_push(top, equation[i], i);
            }
        }
        if (equation[i] == '&' && equation[i + 1] == 'l' && equation[i + 2] == 't') {
            stack_push(top, '<', i);
            continue;
        }
        if (equation[i] == '&' && equation[i + 1] == 'g' && equation[i + 2] == 't') {
            char br, tmp;
            int pos;
            stack_peek(top, pos, br);
            if (type_of_bracket('>') == br) stack_pop(top, tmp);
            else stack_push(top, '>', i);
        }
    }
    if (top) {
        for (int i = 0; i < strlen(marks); i += 1) {
            marks[i] = '0';
        }
        while (top) {
            char br, tmp;
            int pos;
            stack_peek(top, pos, br);
            stack_pop(top, tmp);
            marks[pos] = tmp;
        }
    }
}

void check_brackets()
{
    char* data = new char[256];
    char* equation = new char[256];
    get_form_data(data);
    if (strcmp(data, "") == 0) return;
    get_param_value(equation, "equation", data);
    stackElem* bracket = nullptr;
    char* marks = new char[strlen(equation) + 1];
    check_equation(equation, bracket, marks);
    show_equation(equation, marks);
}