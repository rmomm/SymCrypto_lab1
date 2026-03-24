#include "Header.h"

int main()
{
    string text = readText("text.txt");
    string cleaned = cleanText(text);
    string noSpaces = removeSpaces(cleaned);

    ofstream out("result.txt");

    auto ch = LetterFreq(cleaned);
    auto bg = BigramFreq(cleaned);
    auto bg_no = BigramFreqN(cleaned);

    int total_ch = 0;
    for (auto& p : ch) {
        total_ch += p.second;
    }

    int total_bg = 0;
    for (auto& p : bg) {
        total_bg += p.second;
    }

    int total_no = 0;
    for (auto & p : bg_no) {
        total_no += p.second;
    }

    
    double H1 = calculateH1(ch, total_ch);
    double H2 = calculateH2(bg, total_bg);
    double H2_no = calculateH2(bg_no, total_no);

    auto ch_ns = LetterFreq(noSpaces);
    auto bg_ns = BigramFreq(noSpaces);
    auto bg_no_ns = BigramFreqN(noSpaces);

    int total_ch_ns = 0;
    for (auto& p : ch_ns) {
        total_ch_ns += p.second;
    }

    int total_bg_ns = 0;
    for (auto& p : bg_ns) {
        total_bg_ns += p.second;
    }

    int total_no_ns = 0;
    for (auto& p : bg_no_ns) {
        total_no_ns += p.second;
    }

    double H1_ns = calculateH1(ch_ns, total_ch_ns);
    double H2_ns = calculateH2(bg_ns, total_bg_ns);
    double H2_no_ns = calculateH2(bg_no_ns, total_no_ns);

    out << fixed << setprecision(8);
    out << "З ПРОБІЛАМИ \n";
    out << "H1 = " << H1 << "\n";
    out << "H2 (з перетином) = " << H2 << "\n";
    out << "H2 (без перетину) = " << H2_no << "\n";

    printLetters(cleaned, out);
    printBigram(cleaned, out);
    printBigramN(cleaned, out);

    out << fixed << setprecision(8);
    out << "\n БЕЗ ПРОБІЛІВ \n";
    out << "H1 = " << H1_ns << "\n";
    out << "H2 (з перетином) = " << H2_ns << "\n";
    out << "H2 (без перетину) = " << H2_no_ns<< "\n";

    printLetters(noSpaces, out);
    printBigram(noSpaces, out);
    printBigramN(noSpaces, out);

    out.close();

    return 0;
}