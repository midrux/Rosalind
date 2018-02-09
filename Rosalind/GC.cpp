/*
The GC-content of a DNA string is given by the percentage of symbols in the string that are 'C' or 'G'. For example, the GC-content of "AGCTATAG" is 37.5%. Note that the reverse complement of any DNA string has the same GC-content.
DNA strings must be labeled when they are consolidated into a database. A commonly used method of string labeling is called FASTA format. In this format, the string is introduced by a line that begins with '>', followed by some labeling information. Subsequent lines contain the string itself; the first line to begin with '>' indicates the label of the next string.
In Rosalind's implementation, a string in FASTA format will be labeled by the ID "Rosalind_xxxx", where "xxxx" denotes a four-digit code between 0000 and 9999.
Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).
Return: The ID of the string having the highest GC-content, followed by the GC-content of that string. Rosalind allows for a default error of 0.001 in all decimal answers unless otherwise stated; please see the note on absolute error below.
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Problems.h"
#include "Utils.h"

using namespace std;
using namespace FASTA;

void Problems::SolveGC(ifstream &in, ofstream &out) {
    vector<FASTAFormat> input = ReadFastaFormat(in);

    string currentName, currentDNA;
    string highestGCName = "", highestGCDNA="";
    double currentGCContent=-1, highestGCContent=-1;

    for (FASTAFormat current : input) {
        currentName = current.name;
        currentDNA = current.content;
        double tot = currentDNA.size();
        double gc = count(currentDNA.begin(), currentDNA.end(),'G') +
                    count(currentDNA.begin(), currentDNA.end(), 'C');
        double currentGCContent = 100 * gc / tot;
        if (currentGCContent - highestGCContent > 1e-6) {
            highestGCContent = currentGCContent;
            highestGCName = currentName;
        }
    }
    cout << highestGCName << endl << highestGCContent << endl;
    out << highestGCName << endl << highestGCContent << endl;
}
