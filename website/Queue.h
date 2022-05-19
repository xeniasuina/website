#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct man
{
	std::string fullname;
	std::string gender;
	unsigned int age;
	unsigned int salary;
	std::string visit_for;
};

struct queueElem
{
	/// �������������� ����
	man m;
	/// �������� ����
	queueElem* next = nullptr;
};

struct queue
{
	/// ������ ������� ������� (������)
	queueElem* head = nullptr;
	/// ��������� ������� ������� (�����)
	queueElem* tail = nullptr;
	/// ���������� ��������� � �������
	size_t size = 0;
};


inline man create_elem(string fullname, string gender , unsigned int age, unsigned int salary, string visit_for);

void enqueue(queue& queue, string fullname, string gender, unsigned int age, unsigned int salary, string visit_for);

bool dequeue(queue& queue, man& m);

void clear(queue& queue);

void load_data(const char* filename, queue& empl, queue& unempl);

void export_data(queue& q);
