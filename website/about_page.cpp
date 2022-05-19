#include "about_page.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void show_about_page() {
    //TODO template/about !!image_url \n !header \n paragraph
    ifstream f;
    f.open("template/about");
    vector<string> headers;
    vector<string> paragraphs;
    vector<string> image_links;
    if (f.is_open()) {
        while (!f.eof()) {
            char* line = new char[1024];
            f.getline(line, 1023);
            if (strcmp(line, "") == 0) break;
            if (line[0] == '!') {
                if (line[1] == '!') {
                    image_links.push_back(line);
                }
                headers.push_back(line);
            }
            else {
                paragraphs.push_back(line);
            }
            delete[] line;
        }
        f.close();
    }

    if (headers.empty() || paragraphs.empty()) throw new exception;

    for (int i = 0; i < headers.size(); i += 1) {
        cout <<
            "<div class='about-container'>" <<
            "<div class='about-image'>" <<
            "<img src='" << image_links[i] << "'>" <<
            "</div>"
            "<div class='about-header'>" <<
            headers[i] <<
            "</div>" <<
            "<div class='about-body'>" <<
            paragraphs[i] <<
            "</div>" <<
            "</div>";
    }
}
