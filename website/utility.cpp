#include "utility.h"
#include <cstring>
#include <valarray>

bool is_closed_bracket(char ch) {
	return (ch == ')' || ch == '}' || ch == ']' || ch == '>');
}

bool is_open_bracket(char ch) {
	return (ch == '(' || ch == '{' || ch == '[' || ch == '<');
}

bool is_operand(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '!' || ch == '^');
}

bool is_operator(char ch)
{
	return (is_open_bracket(ch) || is_closed_bracket(ch) || is_operand(ch));
}

bool is_delimeter(char ch) {
	return (ch == ' ' || ch == '=');
}

char type_of_bracket(char ch) {
	switch (ch) {
	case(')'): return '(';
	case(']'): return '[';
	case('}'): return '{';
	case('>'): return '<';
	}
}

int make_int(char* count) {
	if (count[0] == '-') {
		int ans = 0;
		ans += (count[1] - 48);
		for (int i = 2; i < strlen(count); i += 1) {
			ans *= 10;
			ans += (count[i] - 48);
		}
		ans = -ans;
		return ans;
	}
	else {
		int ans = 0;
		ans += (count[0] - 48);
		for (int i = 1; i < strlen(count); i += 1) {
			ans *= 10;
			ans += (count[i] - 48);
		}
		return ans;
	}
}

double make_double(char* value)
{
	double ans = 0.0;
	if (value[0] == '-') {
		ans += value[1] - 48;
		int i = 1;
		while (value[i] != '.' && i < strlen(value)) {
			ans *= 10;
			ans += (value[i] - 48);
			i += 1;
		}
		if (value[i] == '.') {
			for (int j = i, pw = 1; j < strlen(value); j += 1, pw += 1) {
				ans += (value[j] - 48) * pow(10, -pw);
			}
		}
		ans = -ans;
		return ans;
	}
	else {
		int i = 0;
		while (value[i] != '.' && i < strlen(value)) {
			ans *= 10;
			ans += (value[i] - 48);
			i += 1;
		}
		if (value[i] == '.') {
			for (int j = i + 1, pw = 1; j < strlen(value); j += 1, pw += 1) {
				ans += (value[j] - 48) * pow(10, -pw);
			}
		}
		return ans;
	}
}
