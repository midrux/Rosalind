/*
Given two strings ss and tt, tt is a substring of ss if tt is contained as a contiguous collection of symbols in ss (as a result, tt must be no longer than ss).
The position of a symbol in a string is the total number of symbols found to its left, including itself (e.g., the positions of all occurrences of 'U' in "AUGCUUCAGAAAGGUCUUACG" are 2, 5, 6, 15, 17, and 18). The symbol at position ii of ss is denoted by s[i]s[i].
A substring of ss can be represented as s[j:k]s[j:k], where jj and kk represent the starting and ending positions of the substring in ss; for example, if ss = "AUGCUUCAGAAAGGUCUUACG", then s[2:5]s[2:5] = "UGCU".
The location of a substring s[j:k]s[j:k] is its beginning position jj; note that tt will have multiple locations in ss if it occurs more than once as a substring of ss (see the Sample below).
Given: Two DNA strings ss and tt (each of length at most 1 kbp).
Return: All locations of tt as a substring of ss.
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Problems.h"

/*** Knuth-Morris-Pratt ***/
//----------------------------
//Returns a vector containing the zero based index of
//  the start of each match of the string K in S.
//  Matches may overlap
//----------------------------
vector<int> KMP(string S, string K) {
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;

    if (K.size() == 0) {
        matches.push_back(0);
        return matches;
    }
    for (int i = 1; i <= K.size(); i++) {
        int pos = T[i - 1];
        while (pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }
    int sp = 0;
    int kp = 0;
    while (sp < S.size())
    {
        while (kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if (kp == K.size()) matches.push_back(sp - K.size());
    }

    return matches;
}


void Problems::SolveSUBS(ifstream &in, ofstream &out) {
    string s, t;
    in >> s >> t;
    vector<int> ret = KMP(s,t);
    for (int i = 0; i < ret.size(); i++) {
        out << ret[i]+1 << " ";
    }
    out << endl;
}