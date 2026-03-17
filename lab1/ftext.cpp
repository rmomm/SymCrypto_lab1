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
    string alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюяё";

    for (char c : text) {
        c = tolower((unsigned char)c);

        if (alphabet.find(c) != string::npos || c == ' ') {
            result += c;
        }
    }

    return result;
}

void printLetters(const string& text, ofstream& out) {
    map<char, int> freq;
    int total = 0;

    for (char c : text) {
        if (c != ' ') {
            freq[c]++;
            total++;
        }
    }

    vector<pair<char, double>> vec;

    for (auto& p : freq) {
        double prob = (double)p.second / total;
        vec.push_back({ p.first, prob });
    }

    sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second > b.second; 
        }
    );

    out << "Частоти букв:\n";
    for (auto& p : vec) {
        out << p.first << " : " << p.second << "\n";
    }
}

void printBigram(const string& text, ofstream& out) {
    map<string, int> freq;
    set<char> letters;

    int total = 0;

    for (char c : text) {
        if (c != ' ') {
            letters.insert(c);
        }
    }

    for (size_t i = 0; i + 1 < text.size(); i++)
    {
        if (text[i] == ' ' || text[i + 1] == ' ') {
            continue;
        }

        string bg;
        bg += text[i];
        bg += text[i + 1];

        freq[bg]++;
        total++;
    }


    out << "\nМатриця біграм:\n   ";

    for (char c : letters) {
        out << setw(7) << c;
    }
    out << "\n";

    for (char row : letters)
    {
        out << setw(4) << row;

        for (char col : letters)
        {
            string bg;
            bg += row;
            bg += col;

            double prob = (double)freq[bg] / total;
            out << setw(7) << fixed << setprecision(4) << prob;
        }
        out << "\n";
    }
}

string removeSpaces(const string& text) {
    string result;

    for (char c : text) {
        if (c != ' ') {
            result += c;
        }
    }

    return result;
}