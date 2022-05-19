#include "Queue.h"

using namespace std;

void queue_start() {
	setlocale(LC_ALL, "Rus");

	queue credit;
	queue deposit;

	// Загружаем данные в очереди
	load_data("data.txt", credit, deposit);

	//Записываем данные в файлы
	export_data(credit);
	export_data(deposit);
}