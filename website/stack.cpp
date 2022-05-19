#include "stack.h"
#include "equation.h"

void stack_push(stackElem*& top, char x, const int pos)
{
	//������� ������� ����� (��������� � ������)
	stackElem* new_el = new stackElem;
	new_el->c = x;
	new_el->pos = pos;
	//�������� ��������� �� ��������� ������� �����
	new_el->next = top;
	//������������ ��������� �� ������� �����
	top = new_el;
}

bool stack_pop(stackElem*& top, char& x)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	x = top->c;
	//���������� ��������� �� ������� ������� �� ��������� ����������
	stackElem* old_el = top;
	//��������� ������� �����
	top = top->next;
	//������� ������ ��-��� ���������� ��������
	delete old_el;
	return true;
}

bool stack_peek(const stackElem* top, int& pos, char& br)
{
	//�������� ����� �� �������
	if (!top) return false;
	//���������� �������� �������� �����
	pos = top->pos;
	br = top->c;
	return true;
}

void stack_clear(stackElem*& top)
{	
	char x;
	while (top) pop(top, x);
}