#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <cmath>
using namespace std;

string readText(const string& filename);
string cleanText(const string& text);
//string removeSpaces(const string& text);

double calculateH1(const string& text);
//double calculateH2(const string& text);