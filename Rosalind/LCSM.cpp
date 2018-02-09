/*A common substring of a collection of strings is a substring of every member of the collection. We say that a common substring is a longest common substring if there does not exist a longer common substring. For example, "CG" is a common substring of "ACGTACGT" and "AACCGTATA", but it is not as long as possible; in this case, "CGTA" is a longest common substring of "ACGTACGT" and "AACCGTATA".
Note that the longest common substring is not necessarily unique; for a simple example, "AA" and "CC" are both longest common substrings of "AACC" and "CCAA".
Given: A collection of kk (k≤100k≤100) DNA strings of length at most 1 kbp each in FASTA format.
Return: A longest common substring of the collection. (If multiple solutions exist, you may return any single solution.)*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Problems.h"
#include "Utils.h"
using namespace FASTA;

string maxLongest;
int amountMaxLongest;

class Trie {
private:
    int words, prefixes;
    int firstChar;
    vector<Trie> children;
    vector<bool> wordNumber;

public:
    Trie(char firstCharacter = 'A', int words=0) {
        words = prefixes = 0;
    firstChar = (int)firstCharacter;
    wordNumber = vector<bool>(words, false); }

    inline int index(char c) { return c - firstChar; }

    void addWord(string &word, int pos=0, int wordNum=0, bool lastWord=false) {
        wordNumber[wordNum] = true;
        if (word.size() == pos) { ++words; return; }	//One more word
        ++prefixes;
        if (lastWord && pos+1>=maxLongest.size()) {
            bool all = true;
            for (int k = 0; k < wordNumber.size(); k++) {
                if (word[k] == false) { all = false; break; }
            }
            if (all) {
                maxLongest = word.substr(0, pos + 1);
            }
        }
        int idx = index(word[pos]);
        //optimize-space
        while (children.size() <= idx)
            children.push_back(Trie(firstChar));

        children[idx].addWord(word, pos + 1);
    }

    void deleteWord(string &word, int pos) {
        if (word.size() == pos) { if (words>0) --words; if (prefixes>0) --prefixes; }
        int idx = index(word[pos]);
        //optimize-space
        if (children.size() < idx)	// Can not delete
            return;
        children[idx].deleteWord(word, pos + 1);
    }

    int countWords(string &word, int pos) {
        if (words == 0 && prefixes == 0) return 0;
        if (word.size() == pos) return words;
        int idx = index(word[pos]);
        if (children.size() < idx) return 0;
        return children[idx].countWords(word, pos + 1);
    }

    int countPrefixes(string &word, int pos) {
        if (words == 0 && prefixes == 0) return 0;
        if (word.size() == pos) return prefixes;
        int idx = index(word[pos]);
        if (children.size() < idx) return 0;
        return children[idx].countPrefixes(word, pos + 1);
    }

    //Be careful. This is really slow.
    vector<pair<string, int> > allWords() {
        //ret: All words and their number of repetitions
        vector< pair<string, int> > ret;
        if (words > 0) ret.push_back(make_pair("", words));

        for (int i = 0; i<children.size(); i++) {
            if (children[i].words == 0 && children[i].prefixes == 0) continue;
            vector<pair<string, int> > cur = children[i].allWords();
            for (int j = 0; j<cur.size(); j++) {
                string tmp = ""; tmp += (char)(i + firstChar);
                pair<string, int> now = make_pair(tmp + cur[j].first, cur[j].second);
                ret.push_back(now);
            }
        }
        return ret;
    }
};



void Problems::SolveLCSM(ifstream &in, ofstream &out) {
    maxLongest = "", amountMaxLongest = 0;
    vector<FASTAFormat> input = ReadFastaFormat(in);

    string currentName, currentDNA;
    string highestGCName = "", highestGCDNA = "";
    double currentGCContent = -1, highestGCContent = -1;
    int k = 0;
    Trie trie = Trie('A', input.size());
    for (FASTAFormat current : input) {
        currentName = current.name;
        currentDNA = current.content;
        for (int i = 0; i < currentDNA.size(); i++) {
            string sub = currentDNA.substr(i);
            trie.addWord(sub,0,i,(k == input.size()-1));
        }
        k++;
    }
    out << maxLongest << endl;
    cout << maxLongest << endl;
}
