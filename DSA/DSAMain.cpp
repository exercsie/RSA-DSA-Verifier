#include <iostream>
#include <cmath>
#include <random>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"
#include "ComputeR.h"
#include "DSAMain.h"

void DSAMain() {
    int p, q, g, s, privateKey, msgHashNum, publicKey, kPowNegOne, verifySignature;
    std::cout << "Welcome to DSA verifier!\n";
    std::cout << "Please input p: ";
    std::cin >> p;
    std::cout << "Please input q: ";
    std::cin >> q;
    std::cout << "Please input g: ";
    std::cin >> g;
    std::cout << "Please input privateKey: ";
    std::cin >> privateKey;
    std::cout << "Please input H(M): ";
    std::cin >> msgHashNum;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, q-1);

    // find public key
    publicKey = modExp(g, privateKey, p);
    std::cout << "\nThe public key is: " << publicKey << std::endl;

    // compute r and find new random number if r = 0
    int r = 0;
    int k = 0;
    while(r == 0) {
        k = dis(gen);
        r = computeR(g, k, p, q);
    }
    std::cout << "The random number is: " << k << std::endl;
    std::cout << "r is equal to: " << r << std::endl;

    // find inverse of k (random number)
    kPowNegOne = modInverse(k, q);
    std::cout << "K^-1 is: " << kPowNegOne << std::endl;

    // compute s
    s = kPowNegOne * (msgHashNum + r * privateKey) % q;
    std::cout << "s is: " << s << std::endl;

    // signature
    std::cout << "The signature is (" << r << ", " << s << ")\n"; 

    // find inverse of s
    int sPowNegOne = modInverse(s, q);
    std::cout << "s^-1 is: " << sPowNegOne << std::endl;

    // verify signature
    int w = sPowNegOne;
    std::cout << "w is: " << w << std::endl;

    int u1 = (msgHashNum * w) % q;
    std::cout << "u1 is: " << u1 << std::endl;

    int u2 = (r * w) % q;
    std::cout << "u2 is: " << u2 << std::endl;

    int gu1, yu2;
    gu1 = modExp(g, u1, p);
    yu2 = modExp(publicKey, u2, p);

    verifySignature = ((gu1 * yu2) % p) % q;

    std::cout << "verifySignature is: " << verifySignature << std::endl;

    if(verifySignature == r) {
        std::cout << "The signature is valid as " << verifySignature << " == " << r;
    } else {
        std::cout << "The signature is not valid as " << verifySignature << " != " << r;
    }
}