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
}