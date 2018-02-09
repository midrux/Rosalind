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
#include "Problems.h"

void Problems::SolveFIBD(ifstream &in, ofstream &out) {
    short n, m;
    in >> n >> m;
    vector<vector<long long>> fib(102, vector<long long> (22,0));
    fib[1][1] = 1;
    fib[2][2] = 1;
    //fib[i][j] = Amount of rabits at month i with age j
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            fib[i][j] = fib[i - 1][j - 1];
        }
        for (int j = 2; j <= m; j++)
            fib[i][1] += fib[i - 1][j];
    }
    long long ret = 0;
    for(int j = 1; j<=m; j++)
        ret += fib[n][j];
    cout << ret << endl;
    out << ret << endl;
}

