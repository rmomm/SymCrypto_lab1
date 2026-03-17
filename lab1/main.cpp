#include "Header.h"

int main()
{
    string text = readText("text.txt");

    string cleaned = cleanText(text);

    cout << "Original length: " << text.size() << endl;
    cout << "Cleaned length: " << cleaned.size() << endl;

    double H1 = calculateH1(cleaned);

    cout << "H1 = " << H1 << endl;


    return 0;
}