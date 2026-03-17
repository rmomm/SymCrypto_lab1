#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <map>
#include <cmath>
#include<set>
using namespace std;

string readText(const string& filename);
string cleanText(const string& text);
string removeSpaces(const string& text);

double calculateH1(const string& text);
double calculateH2(const string& text);
void printLetters(const string& text, ofstream& out);
void printBigram(const string& text, ofstream& out);