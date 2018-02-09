#pragma once
#include <fstream>
using namespace std;
static class Problems {
public:
    void SolveDNA(ifstream &fin, ofstream &fout);
    void SolveRNA(ifstream &fin, ofstream &fout);
    void SolveREVC(ifstream & in, ofstream & out);
    void SolveIPRB(ifstream & in, ofstream & out);
    void SolveFIB(ifstream & in, ofstream & out);
    void SolveGC(ifstream & in, ofstream & out);
    void SolvePROT(ifstream & in, ofstream & out);
    void SolveSUBS(ifstream & in, ofstream & out);
    void SolveHAMM(ifstream & in, ofstream & out);
    void SolveIEV(ifstream & in, ofstream & out);
    void SolveFIBD(ifstream & in, ofstream & out);
    void SolvePERM(ifstream & in, ofstream & out);
    void SolveLCSM(ifstream & in, ofstream & out);
};
