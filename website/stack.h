#pragma once

/// <summary>
/// ��������� ��� �������� ��������� �����
/// </summary>

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
void push(stackElem*& stack, char x, const int pos);

/// <summary>
/// ������� �� ����� ������� � ���������� ��� ��������
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������</param>
/// <returns>
/// true, ���� ������� ������ �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool pop(stackElem*& stack, char& x);

/// <summary>
/// ���������� �������� �������� � ������� �����, �� ��������� ��� ������� � �����
/// </summary>
/// <param name="stack">��������� �� ������� �����</param>
/// <param name="x">������������ �������� �������� � ������� �����</param>
/// <returns>
/// true, ���� ������� �������� �� ����� ������� �
/// false � ��������� ������
/// </returns>
bool peek(const stackElem* stack, int& pos, char& br);

/// <summary>
/// ������� �������� ����� �� ������ 
/// </summary>
/// <param name="stack">��������� �� ������� ���������� �����</param>
void clear(stackElem*& stack);

