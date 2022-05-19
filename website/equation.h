#pragma once

//void check_equation(const char* equation, stackElem*& top, char*& marks);

struct stackElem
{
	/// <summary>
	/// ����������� � ����� ��������
	/// </summary>
	int pos = 0;
	char c;
	/// <summary>
	/// ��������� �� ��������� ������� � �����
	/// </summary>
	stackElem* next = nullptr;
};

/// <summary>
/// ���������� �������� � ����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">����������� � ����� �������</param>
void stack_push(stackElem*& stack, char x, const int pos);

/// <summary>
/// ������� �� ����� ������� � ���������� ��� ��������
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������</param>
/// <returns>
/// true, ���� ������� ������ �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool stack_pop(stackElem*& stack, char& x);

/// <summary>
/// ���������� �������� �������� � ������� �����, �� ��������� ��� ������� � �����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������� �������� � ������� �����</param>
/// <returns>
/// true, ���� ������� �������� �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool stack_peek(const stackElem* stack, int& pos, char& br);

/// <summary>
/// ������� �������� ����� �� ������ 
/// </summary>
/// <param name="stack">��������� �� ������� ���������� �����</param>
void stack_clear(stackElem*& stack);
