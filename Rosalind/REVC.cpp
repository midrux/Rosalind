/*
An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.
Given a DNA string tt corresponding to a coding strand, its transcribed RNA string uu is formed by replacing all occurrences of 'T' in tt with 'U' in uu.
Given: A DNA string tt having length at most 1000 nt.
Return: The transcribed RNA string of tt.
*/

#include <fstream>
#include <string>
#include <algorithm>
#include "Problems.h"

void Problems::SolveREVC(ifstream &in, ofstream &out) {
    string s;
    in >> s;
    replace(s.begin(), s.end(), 'A', 'B');
    replace(s.begin(), s.end(), 'C', 'D');
    replace(s.begin(), s.end(), 'G', 'H');
    replace(s.begin(), s.end(), 'T', 'U');

    replace(s.begin(), s.end(), 'B', 'T');
    replace(s.begin(), s.end(), 'D', 'G');
    replace(s.begin(), s.end(), 'H', 'C');
    replace(s.begin(), s.end(), 'U', 'A');


    reverse(s.begin(), s.end());
    out << s;
}