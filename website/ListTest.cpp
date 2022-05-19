#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//#include "summator.h"

struct l2_elem {
    int elems[9];
    l2_elem* next = nullptr;
    l2_elem* prev = nullptr;
};

/// <summary>
/// Структура для обьединения указателей, определяющих двусвязный список
/// </summary>
struct list2 {
    /// <summary>
    /// Pervii element spiska
    /// </summary>
    l2_elem* first = nullptr;
    /// <summary>
    /// lastovii element spiska
    /// </summary>
    l2_elem* last = nullptr;

    /// <summary>
    /// chislo elementov v liste
    /// </summary>
    int count = 0;

};
/// <summary>
/// Funkciya dobavlenia elementa v spisok
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
void add(list2& list, int data[]);

bool remove(list2& list, int pos);

const int* get(list2 list, int pos);

void clear(list2& list);

void push_forward(list2& list, int data[]);

char *get_string_from_list(list2 list2);

using namespace std;

//void fill_list(const char* data1, list2& list) {
//	size_t size = strlen(data1);
//
//    for(int i = size - 1; i >= 0; i-=9){
//        char els[9];
//        for(int j = 0; j < 9; j+=1){
//            els[j] = '0';
//        }
//        for(int j = 0; j < 9; j+=1){
//            if(i - j < 0) break;
//            els[j] = data1[i - j];
//        }
//        add(list, els);
//    }
//}

//void show_list(const list2 list) {
//	char* res_str = new char[list.count * 9 + 1];
//	for (int i = 0, j = 0; i < list.count, j < strlen(res_str); i++, j+=9) {
//		const char* els = get(list, i);
//        if(els != nullptr) {
//            for (int k = 0; k < 9; k += 1) {
//                if(els[k] == 'X') break;
//                res_str[j + k] = els[k];
//            }
//        }
//	}
//    int i = 0;
//    do{
//        if(!isdigit(res_str[i])) break;
//        i+=1;
//    }while(true);
//    res_str[i] = '\0';
//	cout << "Result is: " << res_str << endl;
//}

void fill_int_list(list2& list, const char* data){
    size_t data_length = strlen(data);
    for(int i = data_length - 1; i >= 0; i-=9){
        int els_to_add[9];
        for(int j = 0; j < 9; j+=1){
            els_to_add[j] = 0;
        }
        int k = 0;
        for(int j = 8; j >= 0; j -=1){
            if(i - k < 0) break;
            els_to_add[j] = data[i - k] - '0';
            k+=1;
        }
        push_forward(list, els_to_add);
    }
}

vector<int> get_int_vector_from_list(list2 list){
    size_t size = list.count;
    l2_elem* curr = list.first;
    vector<int> res;
    while(curr){
        for(int i = 0; i < 9; i+=1){
            res.push_back(curr->elems[i]);
        }
        curr = curr->next;
    }
    return res;
}

vector<int> sum_of_vectors(vector<int> v1, vector<int> v2){
    vector<int> min_vec = v1.size() > v2.size() ? v2 : v1;
    vector<int> max_vec = v1.size() > v2.size() ? v1 : v2;
    size_t min_size = min_vec.size();
    size_t max_size = max_vec.size();

    for (int (i) = 0; (i) < max_vec.size(); ++(i)) {
        cout << max_vec[i] << " ";
    }
    cout << endl << "+" << endl;
    if(max_size - min_size > 8)
        for(int i = 0; i < 9; i+=1){
            cout << "0 ";
        }
    for(int i = 0; i < min_vec.size(); i+=1){
        cout << min_vec[i] << " ";
    }
    int inc = 1;
    bool flag = true;
    for(int i = max_size - 1, j = min_size - 1; i >= 0 || inc > 0; --i, --j){
//        if(j < 0){
//            if(flag) {
//                int k = 0;
//                while(min_vec[k] == 0) k+=1;
//                inc = (max_vec[i] + min_vec[k]) / 10;
//                flag = false;
//            }
//            max_vec[i] += inc;
//            inc = max_vec[i] / 10;
//            max_vec[i] %= 10;
//            continue;
//        }
        if(j < 0 && inc > 0){
            for(int k = i + 1; k >= 0; k-=1){
                max_vec[k] += inc;

            }
        }
        inc = (max_vec[i] + min_vec[j]) / 10;
        max_vec[i] += min_vec[j];
        max_vec[i] %= 10;
        if(i - 1 < 0 && inc > 0){
            max_vec.insert(max_vec.begin(), inc);
        }
        int k = i - 1;
        while(inc > 0 && k > 0){
            max_vec[k] += inc;
            inc = max_vec[k] / 10;
            max_vec[k] %= 10;
            k-=1;
        }
        if(inc > 0 && k < 0){
            max_vec.insert(max_vec.begin(), inc);
        }
    }

    return max_vec;
}

void show_vector(vector<int> vector){
    int k = 0;
    while(vector[k] == 0){
        k+=1;
    }
    for(int i  = 0; i < vector.size(); i+=1){
        cout << vector[i] << " " ;
    }
}

int summator() {
	char* data1 = new char[120];
    char* data2 = new char[120];
	cout << "Enter data1  ";
	cin >> data1;
	cout << endl;
    cout << "Enter data2  ";
    cin >> data2;
    cout << endl;
	list2 list1, list2;
    fill_int_list(list1, data1);
    fill_int_list(list2, data2);
    vector<int> res1 = get_int_vector_from_list(list1);
    vector<int> res2 = get_int_vector_from_list(list2);
    vector<int> sum =  sum_of_vectors(res1, res2);
    cout << endl <<"Result is:" << endl;
    show_vector(sum);
}

//char *get_string_from_list(list2 list) {
//    char* res_str = new char[list.count * 9 + 1];
//    for (int i = 0, j = 0; i < list.count, j < strlen(res_str); i++, j+=9) {
//        const int els = get(list, i);
//        if(els != nullptr) {
//            res_str[j] = ' ';
//            j+=1;
//            for (int k = 0; k < 9; k += 1) {
//                if(els[k] == 'X') break;
//                res_str[j + k] = els[k];
//            }
//        }
//    }
//    int i = 0;
//    do{
//        if(res_str[i] == ' ') {
//            i+=1;
//            continue;
//        }
//        if(!isdigit(res_str[i])) break;
//        i+=1;
//    }while(true);
//    res_str[i] = '\0';
//    return res_str;
//}
