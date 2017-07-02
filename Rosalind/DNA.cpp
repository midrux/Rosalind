/*
A string is simply an ordered collection of symbols selected from some alphabet and formed into a word; the length of a string is the number of symbols that it contains.
An example of a length 21 DNA string (whose alphabet contains the symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."
Given: A DNA string ss of length at most 1000 nt.
Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in ss.
*/

#include <fstream>
#include <string>
#include "Problems.h"

using namespace std;
struct LetterCount {
    LetterCount() {
        A = C = G = T = 0;
    }
    int A, C, G, T;
};

LetterCount SolveProblem(ifstream &fin) {
    string s;
    fin >> s;
    LetterCount res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') res.A++;
        else if (s[i] == 'C') res.C++;
        else if (s[i] == 'T') res.T++;
        else if (s[i] == 'G') res.G++;
    }
    return res;
}

void Problems::SolveDNA(ifstream & fin, ofstream & fout)
{
    LetterCount res = SolveProblem(fin);
    fout << res.A << " " << res.C << " " << res.G << " " << res.T << endl;
}