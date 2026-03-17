#include "Header.h"

double calculateH1(const string& text) {
    map<char, int> freq;
    int total = 0;

    for (char c : text) {
        if (c != ' ') {
            freq[c]++;
            total++;
        }
    }

    double H1 = 0.0;

    for (auto& pair : freq) {
        double p = (double)pair.second / total;
        H1 -= p * log2(p);
    }

    return H1;
}

double calculateH2(const string& text) {
    map<string, int> freq;
    int total = 0;

    for (size_t i = 0; i + 1 < text.size(); i++) {
        if (text[i] == ' ' || text[i + 1] == ' ') {
            continue;
        }

        string bigram;
        bigram += text[i];
        bigram += text[i + 1];

        freq[bigram]++;
        total++;
    }

    double H2 = 0.0;

    for (auto& pair : freq) {
        double p = (double)pair.second / total;
        H2 -= p * log2(p);
    }

    return H2 / 2.0;
}