#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace FASTA
{
    struct FASTAFormat {
        string name, content;
        FASTAFormat(string _name, string _content) : name(_name), content(_content) {
        }
    };

    vector<FASTAFormat> ReadFastaFormat(ifstream &in);
}
