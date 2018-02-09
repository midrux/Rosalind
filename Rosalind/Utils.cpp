#include "Utils.h"

namespace FASTA
{
    vector<FASTAFormat> ReadFastaFormat(ifstream &in) {
        vector<FASTAFormat> result;
        string line, content, name;
        while (std::getline(in, line).good()) {
            if (line.empty() || line[0] == '>') { // Identifier marker
                if (!name.empty()) { // Print out what we read from the last entry
                    result.push_back(FASTAFormat(name, content));
                    name.clear();
                }
                if (!line.empty()) {
                    name = line.substr(1);
                }
                content.clear();
            }
            else if (!name.empty()) {
                if (line.find(' ') != std::string::npos) { // Invalid sequence--no spaces allowed
                    name.clear();
                    content.clear();
                }
                else {
                    content += line;
                }
            }
        }
        if (!name.empty()) { // Print out what we read from the last entry
            result.push_back(FASTAFormat(name, content));
        }
        return result;
    }
}