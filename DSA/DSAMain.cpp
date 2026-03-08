#include <iostream>
#include <cmath>
#include <random>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"
#include "ComputeR.h"
#include "DSAMain.h"

void DSAMain() {
    long long int p, q, g, privateKey, msgHashNum;
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
    long long int publicKey;
    publicKey = modExp(g, privateKey, p);
    std::cout << "\nThe public key is: " << publicKey << std::endl;

    // compute r and find new random number if r = 0
    int r = 0, s = 0;
    long long int kPowNegOne = 0, sPowNegOne = 0, verifySignature = 0;
    bool found = false;
    long long int attempts = 0, maxAttempts = q * 10;
    while(!found) {
        attempts++;
        if(attempts > maxAttempts) {
            std::cout << "Could not find a valid signature, tried " << maxAttempts << " times.\n";
            return;
        }

        long long int k = dis(gen);
        std::cout << "Rand num: " << k << std::endl;

        // compute r
        r = computeR(g, k, p, q);
        if(r == 0) {
            continue;
        }

        // find inverse of k (random number)
        kPowNegOne = modInverse(k, q);

        // compute s
        s = kPowNegOne * (msgHashNum + r * privateKey) % q;
        if(s == 0) {
            continue;
        }

        // find inverse of s
        long long int sPowNegOne = modInverse(s, q);

        // verify signature
        long long int w = sPowNegOne;
        long long int u1 = (msgHashNum * w) % q;
        long long int u2 = (r * w) % q;

        long long int gu1, yu2;
        gu1 = modExp(g, u1, p);
        yu2 = modExp(publicKey, u2, p);

        verifySignature = ((gu1 * yu2) % p) % q;

        if(verifySignature == r) {
            found = true;
            std::cout << "Valid signature found!\n";
            std::cout << "Random number k: " << k << std::endl;
            std::cout << "K^-1: " << kPowNegOne << std::endl;
            std::cout << "r: " << r << std::endl;
            std::cout << "s: " << s << std::endl;
            std::cout << "Signature: (" << r << ", " << s << ")\n"; 
            std::cout << "s^-1: " << sPowNegOne << std::endl;
            std::cout << "verifySignature: " << verifySignature << std::endl;
            std::cout << "The signature is valid as " << verifySignature << " == " << r;
        }

    }

}   
