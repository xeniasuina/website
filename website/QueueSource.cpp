#include "Queue.h"

using namespace std;

inline man create_elem(string fullname, string gender, unsigned int age, unsigned int salary, string visit_for)
{
    man m;
    // Если бы в структуре была строка в виде динамического массива, здесь нужно было бы
    // предварительно выделить память под эту строку!
    m.fullname.assign(fullname);
    m.gender.assign(gender);
    m.age = age;
    m.salary = salary;
    m.visit_for.assign(visit_for);
    return m;
}

void enqueue(queue& queue, string fullname, string gender, unsigned int age, unsigned int salary, string visit_for)
{
    // Создаем новый элемент для размещения в очереди
    man newm = create_elem(fullname, gender, age, salary, visit_for);
    queueElem* newel = new queueElem;
    newel->m = newm;
    if (!queue.tail)
    {
        // Если очереди еще не было, новый элемент становится единственным в ней
        queue.head = queue.tail = newel;
    }
    else
    {
        // Если очередь уже была, новый элемент помещается в конец:
        queue.tail->next = newel;
        queue.tail = newel;
    }
    queue.size++;
}

bool dequeue(queue& queue, man& m)
{
    if (!queue.head) // Очереди нет
        return false; // Вернуть значение невозможно
   // Сохраняем возвращаемое значение
    m = queue.head->m;
    // Сохраняем указатель на начало очереди
    queueElem* rem = queue.head;
    // Изменяем адрес головного элемента
    queue.head = queue.head->next;
    // Если бы в структуре была строка в виде динамического массива, здесь нужно было бы
    // предварительно очистить память из-под этой строки!
    // Удаляем элемент с головы очереди
    delete rem;
    // Если элементов в очереди не осталось, обнуляем и указатель на ее конец.
    if (!queue.head) queue.tail = nullptr;
    queue.size--;
    return true;
}

void clear(queue& queue)
{
    // Проходим по всем элементам очереди, пока она не опустеет
    while (queue.head)
    {
        queueElem* rem = queue.head; // Сохраняем ссылку на удаляемый элемент
        queue.head = queue.head->next;// Переносим "голову" очереди вперед
        delete rem; // Удаляем элемент по сохраненному указателю
    }
    queue.size = 0; // Обнуляем размер очереди
    queue.tail = nullptr; // Обновляем указатель на последний элемент
}


void load_data(const char* filename, queue& credit, queue& deposit)
{
    ifstream f(filename);
    if (f.is_open())
    {
        //До конца файла
        while (!f.eof())
        {
            char* man = new char[256];
            //Считываем очередную строку
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
            //Получаем имя и возраст человека в отдельных переменных
            //sscanf_s(man, "%s%c%s%c%s|%s|%d|%d|%d", fullname, gender, &age, &salary, visit_for);

            if (visit_for.compare("кредит") == 0) {
                enqueue(credit, fullname, gender, age, salary, visit_for);
            }
            else if (visit_for.compare("вклад") == 0) {
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

