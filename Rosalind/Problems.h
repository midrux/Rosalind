#pragma once
#include <fstream>
using namespace std;
static class Problems {
public:
    void SolveDNA(ifstream &fin, ofstream &fout);
    void SolveRNA(ifstream &fin, ofstream &fout);
    void SolveREVC(ifstream & in, ofstream & out);
};
