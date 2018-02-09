/*
Recall the definition of the Fibonacci numbers from “Rabbits and Recurrence Relations”, which followed the recurrence relation Fn=Fn−1+Fn−2Fn=Fn−1+Fn−2 and assumed that each pair of rabbits reaches maturity in one month and produces a single pair of offspring (one male, one female) each subsequent month.
Our aim is to somehow modify this recurrence relation to achieve a dynamic programming solution in the case that all rabbits die out after a fixed number of months. See Figure 4 for a depiction of a rabbit tree in which rabbits live for three months (meaning that they reproduce only twice before dying).
Given: Positive integers n≤100n≤100 and m≤20m≤20.
Return: The total number of pairs of rabbits that will remain after the nn-th month if all rabbits live for mm months.
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Problems.h"

void Problems::SolvePERM(ifstream &in, ofstream &out) {
    short n;
    in >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i+1;
    vector<vector<int> > result;
    do {
        result.push_back(p);
    } while (next_permutation(p.begin(), p.end()));
    out << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            out << result[i][j] << " ";
        }
        out << endl;
    }
}

