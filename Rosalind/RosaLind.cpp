#include <iostream>
#include <fstream>
#include "Problems.h"
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    Problems p;
    p.SolveLCSM(fin,fout);
    system("PAUSE");
    return 0;
}