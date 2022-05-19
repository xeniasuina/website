#include "controller.h"
#include "main.h"
#include "cgi.h"
#include "stack.h"
#include "utility.h"
#include "pageloader.h"
#include "Queue.h"
#include "list1.h"
#include "list2.h"
#include "longSummator.h"

using namespace std;

vector<string> get_menu(string path)
{
    vector<string> res{};
    ifstream f;
    f.open(path);
    if (f.is_open()) {
        while (!f.eof()) {
            char* line = new char[257];
            f.getline(line, 256);
            if (strcmp(line, "") == 0) continue;
            res.push_back(line);
        }
        f.close();
    }
    return res;
}



