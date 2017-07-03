#include <iostream>
#include <fstream>
#include "Problems.h"
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    Problems p;
    p.SolveREVC(fin,fout);

    return 0;
}