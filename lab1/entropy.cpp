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