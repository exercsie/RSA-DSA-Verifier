#include <iostream>
#include <cmath>
#include "../ModularExponentiation.h"
#include "../RSA/EuclidsExtendedAlgorithm.h"

void TSAMain() {
    long long int p, q, m;
    std::cout << "Enter p: ";
    std::cin >> p;
    std::cout << "Enter q: ";
    std::cin >> q;
    std::cout << "Enter m: ";
    std::cin >> m;

    long long int n;
    n = p * q;
    std::cout << "n: " << n << std::endl;

    long long int phiNMinusOne;
    phiNMinusOne = n - p - q;
    std::cout << "phi(n)-1: " << phiNMinusOne << std::endl;

    long long int nPhiNProduct;
    nPhiNProduct = phiNMinusOne * n;
    std::cout << "nphi(n)-1: " << nPhiNProduct << std::endl;

    long long int average;
    average = (phiNMinusOne + n) / 2;
    std::cout << "average: " << average << std::endl;

    long long int seed;
    seed = phiNMinusOne - average;
    std::cout << "seed: " << seed << std::endl;
}