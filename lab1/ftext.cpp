#include "Header.h"

string readText(const string& filename) {
    ifstream file(filename);

    string text;
    string line;

    while (getline(file, line)) {
        text += line + " ";
    }
    return text;
}

string cleanText(const string& text) {
    string result;

    for (char c : text)  {
        if (isalpha((unsigned char)c) || c == ' ') {
            result += tolower((unsigned char)c);
        }
    }

    return result;
}