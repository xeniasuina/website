#include <iostream>
#include "pageloader.h"
#include "about_page.h"
#include "query_split.h"
#include "equation.h"
#include "unique_list.h"
#include "utility.h"
#include "longSummator.h"
#include "tree.h"
using namespace std;

void show_dashboard()
{
	cout << "<div class='user'>";
	show_user();
	cout << "</div>";
	cout << "<div class='menu'>";
	show_menu();
	cout << "</div>";
}

void show_radio_form() {
	cout
		//<< "<input type='text' name='" << name << "' placeholder='" << placeholder << "'>"
		<< "<div class='tree-form'><form method='get' action='tree.cgi'>"
		<< "<div class='form_radio_btn'>"
		<< "<input class='dot' id='dot-1' type='radio' name='choose' value='false'>"
		<< "<label for='dot-1'><h2> Sort by name </h2></label>"
		<< "</div><div class='form_radio_btn'>"
		<< "<input class='dot' id='dot-2' type='radio' name='choose' value='true'>"
		<< "<label for='dot-2'><h2> Sort by middle value </h2></label>"
		<< "</div>"
		<< "</form></div></div>";
	//<< "<button class='page52-button'><h3>I'm feeling lucky</h3></button>"
}

void show_content(int choose)
{
	switch (choose) {
	case 0:
		show_about_page();
		break;
	case 1: //brackets
		form_constructor(choose);
		check_brackets();
		break;
	case 2: // queries
        query_split();
		break;
	case 3: //uniqueList
		form_constructor(choose);
		unique_list();
		break;
	case 4: // longSummator
		cout << "<div class='sum-info'><p> Введите значения для суммирования через пробел </p></div>";
		form_constructor(choose);
		summator();
		break;
	case 5:
		form_constructor(choose);
		tree_start();
		break;
	}

}

void show_user()
{
	//cout << "<img src='/images/4e95b4c2884d95985a9e9d3d77b6052e.png'>";
	cout << "<h2> Xenia </h2>"
		<< "<p> zayechka </p>";
}

void show_menu()
{
	vector<string> menu = get_menu("template/menu");
	for (int i = 0; i < menu.size(); i += 1) {
		char* dup = _strdup(menu[i].c_str());
		char* part2;
		strtok_s(dup, " ", &part2);
		cout << "<div class='menu-item'><a href='"
			<< dup << "'><h2>" <<
			part2 << "</h2></a></div>";
		free(dup);
		free(part2);
	}
}

void _show_form(string pagename, string formname, bool button) {
	cout << "<div class='form'><form action='" << pagename << "' method='post'>"
		<< "<input type='text' required name='" << formname << "' placeholder='Enter the equation'>";
	if (button) cout << "<button class='button'><h3>Check!<h3></button>";
	cout << "</form></div>";
}

void form_constructor(int choose)
{
	string pagename;
	string formname;
	switch (choose) {
	case 1:
		pagename = "brackets.cji";
		formname = "equation";
		_show_form(pagename, formname, true);
		break;
	case 3:
		pagename = "unique_list.cgi";
		formname = "value";
		_show_form(pagename, formname, false);
		formname = "position";
		_show_form(pagename, formname, true);
		break;
	case 4:
		pagename = "sum_list.cgi";
		formname = "summ";
		_show_form(pagename, formname, true);
		break;
	case 5:
		show_radio_form();
		pagename = "tree.cgi";
		formname = "bottom_border";
		_show_form(pagename, formname, false);
		formname = "upper_border";
		_show_form(pagename, formname, true);
		break;
	}
}

void show_page(string path, int choose)
{
	cout << "Content-type: text/html; charset=Windows-1251\n\n";
	ifstream f;
	f.open(path);
	if (f.is_open()) {
		while (!f.eof()) {
			char* line = new char[257];
			f.getline(line, 256);
			if (strcmp(line, "<!--dashboard-->") == 0) {
				show_dashboard();
			}
			else if (strcmp(line, "<!--content-->") == 0) {
				show_content(choose);
			}
			else {
				cout << line;
			}
			delete[] line;
		}
		f.close();
	}
	else {
		cout << "Can't load page";
	}
}

void show_equation(const char* equation, const char* marks)
{
	cout << "<div class='res-eq'>";
	size_t sz = strlen(equation);
	for (int i = 0; i < sz; i += 1) {
		if (!is_open_bracket(marks[i]) && !is_closed_bracket(marks[i])) {
			cout << equation[i];
		}
		else if (marks[i] == '>' || marks[i] == '<') {
			cout << "<mark>" << marks[i] << "</mark>";
			i += 2;
		}
		else {
			cout << "<mark>" << marks[i] << "</mark>";
		}
	}
	cout << "</div>";
}

void show_queries()
{
	cout << "<div class='queries'>";
	ifstream c, d;
	c.open("кредит.txt");
	if (c.is_open()) {
		cout << "<div class='query'>";
		while (!c.eof()) {
			char* line = new char[512];
			c.getline(line, 511);
			cout << line << "<br>";
		}
		cout << "</div>";
		c.close();
	}
	d.open("депозит.txt");
	if (d.is_open()) {
		cout << "<div class='query'>";
		while (!d.eof()) {
			char* line = new char[512];
			c.getline(line, 511);
			cout << line << "<br>";
		}
		cout << "</div>";
		d.close();
	}
	cout << "</div>";
}
