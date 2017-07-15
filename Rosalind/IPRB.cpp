/*Probability is the mathematical study of randomly occurring phenomena. We will model such a phenomenon with a random variable, which is simply a variable that can take a number of different distinct outcomes depending on the result of an underlying random process.
For example, say that we have a bag containing 3 red balls and 2 blue balls. If we let XX represent the random variable corresponding to the color of a drawn ball, then the probability of each of the two outcomes is given by Pr(X=red)=35Pr(X=red)=35 and Pr(X=blue)=25Pr(X=blue)=25.
Random variables can be combined to yield new random variables. Returning to the ball example, let YY model the color of a second ball drawn from the bag (without replacing the first ball). The probability of YY being red depends on whether the first ball was red or blue. To represent all outcomes of XX and YY, we therefore use a probability tree diagram. This branching diagram represents all possible individual probabilities for XX and YY, with outcomes at the endpoints ("leaves") of the tree. The probability of any outcome is given by the product of probabilities along the path from the beginning of the tree; see Figure 2 for an illustrative example.
An event is simply a collection of outcomes. Because outcomes are distinct, the probability of an event can be written as the sum of the probabilities of its constituent outcomes. For our colored ball example, let AA be the event "YY is blue." Pr(A)Pr(A) is equal to the sum of the probabilities of two different outcomes: Pr(X=blue and Y=blue)+Pr(X=red and Y=blue)Pr(X=blue and Y=blue)+Pr(X=red and Y=blue), or 310+110=25310+110=25 (see Figure 2 above).
Given: Three positive integers kk, mm, and nn, representing a population containing k+m+nk+m+n organisms: kk individuals are homozygous dominant for a factor, mm are heterozygous, and nn are homozygous recessive.
Return: The probability that two randomly selected mating organisms will produce an individual possessing a dominant allele (and thus displaying the dominant phenotype). Assume that any two organisms can mate.*/

#include <fstream>
#include <string>
#include "Problems.h"

double k, m, n;

#define MAX 450
double choose[MAX][MAX];
inline double binomial(int n, int r) {
    if (n < 0 || r < 0 || r > n)  return 0;
    if (n == 0)   return r == 0 ? 1 : 0;
    if (choose[n][r] >= 0)  return choose[n][r];
    return choose[n][r] = binomial(n - 1, r) + binomial(n - 1, r - 1);
}

//k homozygous dominant (hd)
//m heterozygous (he)
//n homozygous recessive (hr)

//1-P(yy)
//P(yy) = (hr)-(hr) + (hr)-(he)*1/2 or (he)-(he)*1/4

void Problems::SolveIPRB(ifstream &in, ofstream &out) {
    memset(choose, -1, sizeof(choose));
    in >> k >> m >> n;
    double totalWays = binomial(n+m+k,2)*4;
    double p2hr = (binomial(n,2)*4) / totalWays;
    double phehe = (binomial(m, 2)) / totalWays;
    double phrhe = ((n*m)*2) / totalWays;

    double p2recessive = p2hr + phrhe + phehe;

    double ret = 1.0 - p2recessive;
    out << ret;
}