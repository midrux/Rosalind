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

void Problems::SolveRNA(ifstream &in, ofstream &out) {
    string s;
    in >> s;
    replace(s.begin(), s.end(), 'T', 'U');
    out << s;
}