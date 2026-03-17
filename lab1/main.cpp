#include "Header.h"

int main()
{
    string text = readText("text.txt");
    string cleaned = cleanText(text);
    string noSpaces = removeSpaces(cleaned);

    ofstream out("result.txt");

    double H1 = calculateH1(cleaned);
    double H2 = calculateH2(cleaned);

    double H1_ns = calculateH1(noSpaces);
    double H2_ns = calculateH2(noSpaces);

    out << "Ç ÏÐÎÁ²ËÀÌÈ \n";
    out << "H1 = " << H1 << "\n";
    out << "H2 = " << H2 << "\n";

    printLetters(cleaned, out);
    printBigram(cleaned, out);

    out << "\n ÁÅÇ ÏÐÎÁ²Ë²Â \n";
    out << "H1 = " << H1_ns << "\n";
    out << "H2 = " << H2_ns << "\n";

    printLetters(noSpaces, out);
    printBigram(noSpaces, out);

    out.close();

    return 0;
}