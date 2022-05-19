#pragma once
#include <iostream>
using namespace std;

bool is_open_bracket(char ch);

bool is_closed_bracket(char ch);

bool is_operand(char ch);

bool is_operator(char ch);

bool is_delimeter(char ch);

char type_of_bracket(char ch);

int make_int(char* count);

double make_double(char* value);

