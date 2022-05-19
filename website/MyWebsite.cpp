#include "main.h"
#include "pageloader.h"
#include "controller.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	string path = "template/index";
	int choose = 0;
	show_page(path, choose);
    return 0;
}