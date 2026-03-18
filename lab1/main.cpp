#include "Header.h"

int main()
{
    string text = readText("text.txt");
    string cleaned = cleanText(text);
    string noSpaces = removeSpaces(cleaned);

    ofstream out("result.txt");

    auto charFreq = LetterFreq(cleaned);
    auto bigramFreq = BigramFreq(cleaned);

    int totalChars = 0;
    for (auto& p : charFreq) {
        totalChars += p.second;
    }

    int totalBigrams = 0;
    for (auto& p : bigramFreq) {
        totalBigrams += p.second;
    }

    double H1 = calculateH1(charFreq, totalChars);
    double H2 = calculateH2(bigramFreq, totalBigrams);

    auto charFreq_ns = LetterFreq(noSpaces);
    auto bigramFreq_ns = BigramFreq(noSpaces);

    int totalChars_ns = 0;
    for (auto& p : charFreq_ns) {
        totalChars_ns += p.second;
    }

    int totalBigrams_ns = 0;
    for (auto& p : bigramFreq_ns) {
        totalBigrams_ns += p.second;
    }

    double H1_ns = calculateH1(charFreq_ns, totalChars_ns);
    double H2_ns = calculateH2(bigramFreq_ns, totalBigrams_ns);


    out << "Ç ÏÐÎÁ²ËÀÌÈ\n";
    out << "H1 = " << H1 << "\n";
    out << "H2 = " << H2 << "\n";

    printLetters(cleaned, out);
    printBigram(cleaned, out);

    out << "\nÁÅÇ ÏÐÎÁ²Ë²Â\n";
    out << "H1 = " << H1_ns << "\n";
    out << "H2 = " << H2_ns << "\n";

    printLetters(noSpaces, out);
    printBigram(noSpaces, out);

    out.close();

    return 0;
}