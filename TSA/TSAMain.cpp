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
    seed = modExp(nPhiNProduct, 1, average);
    std::cout << "seed: " << seed << std::endl;

    long long int eSeed;
    eSeed = phiNMinusOne - seed;
    std::cout << "eSeed: " << eSeed << std::endl;

    long long int e;
    e = modExp(nPhiNProduct, 1, eSeed);
    std::cout << "e: " << e << std::endl;

    long long int d;
    d = miniEuclidsExtendedAlgorithm(e, nPhiNProduct);
    std::cout << "d: " << d << std::endl;

    long long int c;
    c = modExp(m, e, n);
    std::cout << "c: " << c << std::endl;

    long long int hiddenMessage;
    hiddenMessage = modExp(c, d, phiNMinusOne);
    std::cout << "Hidden message num: " << hiddenMessage << std::endl;
    
    // this is still kinda bad, it assumes we have m at decryption
    // TODO: use RSA to encrypt and decrypt m then apply it to the delta against hiddenMessage
    long long int delta;
    delta = hiddenMessage - m;
    std::cout << "delta(hidden message, m): " << delta << std::endl;

    long long int checkValue;
    checkValue = modExp(hiddenMessage, 1, delta);
    std::cout << "value: " << checkValue << std::endl;

    if(checkValue == m) {
        std::cout << "Valid as " << checkValue << " == " << m << std::endl;
    } else {
        std::cout << "Invalid as " << checkValue << " != " << m << std::endl;
    }

    //this doesn't work, it assumes we have m on decryption which is impossible
    /* long long int x;
    x = hiddenMessage - m;
    std::cout << "x: " << x << std::endl;

    long long int diff;
    diff = x - c;
    std::cout << "diff: " << d << std::endl;

    long long int ciphHash;
    ciphHash = c + m;
    std::cout << "ciphHash: " << ciphHash << std::endl;

    long long int mPrime;
    mPrime = hiddenMessage - ciphHash;
    std::cout << "mPrime: " << mPrime << std::endl;

    if(mPrime == diff) {
        std::cout << "Valid as " << mPrime << " == " << diff << std::endl;
    } else {
        std::cout << "Invalid as " << mPrime << " != " << diff << std::endl; 
    }
    */
}