#include "Queue.h"

using namespace std;

inline man create_elem(string fullname, string gender, unsigned int age, unsigned int salary, string visit_for)
{
    man m;
    // ���� �� � ��������� ���� ������ � ���� ������������� �������, ����� ����� ���� ��
    // �������������� �������� ������ ��� ��� ������!
    m.fullname.assign(fullname);
    m.gender.assign(gender);
    m.age = age;
    m.salary = salary;
    m.visit_for.assign(visit_for);
    return m;
}

void enqueue(queue& queue, string fullname, string gender, unsigned int age, unsigned int salary, string visit_for)
{
    // ������� ����� ������� ��� ���������� � �������
    man newm = create_elem(fullname, gender, age, salary, visit_for);
    queueElem* newel = new queueElem;
    newel->m = newm;
    if (!queue.tail)
    {
        // ���� ������� ��� �� ����, ����� ������� ���������� ������������ � ���
        queue.head = queue.tail = newel;
    }
    else
    {
        // ���� ������� ��� ����, ����� ������� ���������� � �����:
        queue.tail->next = newel;
        queue.tail = newel;
    }
    queue.size++;
}

bool dequeue(queue& queue, man& m)
{
    if (!queue.head) // ������� ���
        return false; // ������� �������� ����������
   // ��������� ������������ ��������
    m = queue.head->m;
    // ��������� ��������� �� ������ �������
    queueElem* rem = queue.head;
    // �������� ����� ��������� ��������
    queue.head = queue.head->next;
    // ���� �� � ��������� ���� ������ � ���� ������������� �������, ����� ����� ���� ��
    // �������������� �������� ������ ��-��� ���� ������!
    // ������� ������� � ������ �������
    delete rem;
    // ���� ��������� � ������� �� ��������, �������� � ��������� �� �� �����.
    if (!queue.head) queue.tail = nullptr;
    queue.size--;
    return true;
}

void clear(queue& queue)
{
    // �������� �� ���� ��������� �������, ���� ��� �� ��������
    while (queue.head)
    {
        queueElem* rem = queue.head; // ��������� ������ �� ��������� �������
        queue.head = queue.head->next;// ��������� "������" ������� ������
        delete rem; // ������� ������� �� ������������ ���������
    }
    queue.size = 0; // �������� ������ �������
    queue.tail = nullptr; // ��������� ��������� �� ��������� �������
}


void load_data(const char* filename, queue& credit, queue& deposit)
{
    ifstream f(filename);
    if (f.is_open())
    {
        //�� ����� �����
        while (!f.eof())
        {
            char* man = new char[256];
            //��������� ��������� ������
            f.getline(man, 256);

            const char delim = '|';

            vector<std::string> elems;

            stringstream stringstr(man);
            string item;
            while (std::getline(stringstr, item, delim))
            {
                elems.push_back(item);
            }

            if (elems.size() < 4) throw new exception;

            string fullname = elems[0];
            string gender = elems[1];
            unsigned int age = stoi(elems[2]);
            unsigned int salary = stoi(elems[3]);
            string visit_for = elems[4];
            //�������� ��� � ������� �������� � ��������� ����������
            //sscanf_s(man, "%s%c%s%c%s|%s|%d|%d|%d", fullname, gender, &age, &salary, visit_for);

            if (visit_for.compare("������") == 0) {
                enqueue(credit, fullname, gender, age, salary, visit_for);
            }
            else if (visit_for.compare("�����") == 0) {
                enqueue(deposit, fullname, gender, age, salary, visit_for);
            }
        }
        f.close();
    }
}

void export_data(queue& q)
{
    man m;
    if (q.size > 0) {
        dequeue(q, m);
    }
    ofstream f(m.visit_for + ".txt");
    if (f.is_open()) {
        string put = m.fullname + " " + m.gender + " " + to_string(m.age) + " " + to_string(m.salary);
        f << put << endl;

        while (q.size > 0) {
            dequeue(q, m);
            string put = m.fullname + " " + m.gender + " " + to_string(m.age) + " " + to_string(m.salary);
            f << put << endl;
        }
    }
}

