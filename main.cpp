#include <iostream>
#include <cmath>
#include <random>
#include "modularExponention.h"

int main() {
    int p, q, g, r, s, privateKey, msgHashNum, publicKey, kPowNegOne, verifySignature;
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
    int k = 0;
    while(r == 0) {
        k = dis(gen);
        r = modExp(g, k, p) % q;
    }
    std::cout << "r is equal to: " << r << std::endl;

    // compute K^-1
    for(int i = 1; i < q; i++ {
        if((k * i) % q == 1) {
            kPowNegOne = i;
            std::cout << "K^-1 is: " << kPowNegOne << std::endl;
            break;
        }
    }

    // compute s
    s = kPowNegOne * (msgHashNum + r * privateKey) % q;
    std::cout << "s is: " << s << std::endl;

    // signature
    std::cout << "The signature is (" << r << ", " << s << ")\n"; 

}