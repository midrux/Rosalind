/*The 20 commonly occurring amino acids are abbreviated by using 20 letters from the English alphabet (all letters except for B, J, O, U, X, and Z). Protein strings are constructed from these 20 symbols. Henceforth, the term genetic string will incorporate protein strings along with DNA strings and RNA strings.
The RNA codon table dictates the details regarding the encoding of specific codons into the amino acid alphabet.
Given: An RNA string ss corresponding to a strand of mRNA (of length at most 10 kbp).
Return: The protein string encoded by ss.*/

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Problems.h"
using namespace std;
map<string, string> Ctable;
/*
UUU F      CUU L      AUU I      GUU V
UUC F      CUC L      AUC I      GUC V
UUA L      CUA L      AUA I      GUA V
UUG L      CUG L      AUG M      GUG V
UCU S      CCU P      ACU T      GCU A
UCC S      CCC P      ACC T      GCC A
UCA S      CCA P      ACA T      GCA A
UCG S      CCG P      ACG T      GCG A
UAU Y      CAU H      AAU N      GAU D
UAC Y      CAC H      AAC N      GAC D
UAA Stop   CAA Q      AAA K      GAA E
UAG Stop   CAG Q      AAG K      GAG E
UGU C      CGU R      AGU S      GGU G
UGC C      CGC R      AGC S      GGC G
UGA Stop   CGA R      AGA R      GGA G
UGG W      CGG R      AGG R      GGG G
*/
void Problems::SolvePROT(ifstream &in, ofstream &out) {
    Ctable["UUU"] = "F"; Ctable["CUU"] = "L"; Ctable["AUU"] = "I"; Ctable["GUU"] = "V";
    Ctable["UUC"] = "F"; Ctable["CUC"] = "L"; Ctable["AUC"] = "I"; Ctable["GUC"] = "V";
    Ctable["UUA"] = "L"; Ctable["CUA"] = "L"; Ctable["AUA"] = "I"; Ctable["GUA"] = "V";
    Ctable["UUG"] = "L"; Ctable["CUG"] = "L"; Ctable["AUG"] = "M"; Ctable["GUG"] = "V";
    Ctable["UCU"] = "S"; Ctable["CCU"] = "P"; Ctable["ACU"] = "T"; Ctable["GCU"] = "A";
    Ctable["UCC"] = "S"; Ctable["CCC"] = "P"; Ctable["ACC"] = "T"; Ctable["GCC"] = "A";
    Ctable["UCA"] = "S"; Ctable["CCA"] = "P"; Ctable["ACA"] = "T"; Ctable["GCA"] = "A";
    Ctable["UCG"] = "S"; Ctable["CCG"] = "P"; Ctable["ACG"] = "T"; Ctable["GCG"] = "A";
    Ctable["UAU"] = "Y"; Ctable["CAU"] = "H"; Ctable["AAU"] = "N"; Ctable["GAU"] = "D";
    Ctable["UAC"] = "Y"; Ctable["CAC"] = "H"; Ctable["AAC"] = "N"; Ctable["GAC"] = "D";
    Ctable["UAA"] = "."; Ctable["CAA"] = "Q"; Ctable["AAA"] = "K"; Ctable["GAA"] = "E";
    Ctable["UAG"] = "."; Ctable["CAG"] = "Q"; Ctable["AAG"] = "K"; Ctable["GAG"] = "E";
    Ctable["UGU"] = "C"; Ctable["CGU"] = "R"; Ctable["AGU"] = "S"; Ctable["GGU"] = "G";
    Ctable["UGC"] = "C"; Ctable["CGC"] = "R"; Ctable["AGC"] = "S"; Ctable["GGC"] = "G";
    Ctable["UGA"] = "."; Ctable["CGA"] = "R"; Ctable["AGA"] = "R"; Ctable["GGA"] = "G";
    Ctable["UGG"] = "W"; Ctable["CGG"] = "R"; Ctable["AGG"] = "R"; Ctable["GGG"] = "G";
    string s,res;
    in >> s;
    for (int i = 0; i < s.size(); i += 3) {
        string t = Ctable[s.substr(i, 3)];
        if (t == ".") break;
        res += t;
    }
    cout << res << endl;
    out << res << endl;
}