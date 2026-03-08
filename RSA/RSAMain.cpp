#include <iostream>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"
#include "ModularSecondNumPart.h"
#include "EuclidsExtendedAlgorithm.h"
#include "RSAMain.h"

void RSAMain() {
    int p, q, e, m;
    std::cout << "Welcome to RSA verifier!\n";
    std::cout << "Please input first prime number, p: ";
    std::cin >> p;
    std::cout << "Please input sencond prime number, q: ";
    std::cin >> q;
    std::cout << "Please input public key, e: ";
    std::cin >> e;
    std::cout << "Please input plain text number, m: ";
    std::cin >> m;

    // find modulus
    long long int n;
    n = p * q;
    std::cout << "n is: " << n << std::endl;

    long long int phiN;
    phiN = (p-1)*(q-1);
    std::cout << "phi(n) is: " << phiN << std::endl;

    // find private key
    long long int d = miniEuclidsExtendedAlgorithm(e, phiN);
    if(d == -1) {
        std::cout << "e and phiN are not coprime, therefore modular inverse does not exist.\n";
        return;
    }
    
    std::cout << "d is: " << d << std::endl;

    // encrypt message
    long long int ciphertext;
    ciphertext = modExp(m, e, n);
    std::cout << "ciphertext key is: " << ciphertext << std::endl;

    // decrypt message
    long long int mPrime;
    mPrime = modExp(ciphertext, d, n);
    std::cout << "m prime is: " << mPrime << std::endl;

    if(mPrime == m) {
        std::cout << "RSA is valid!\n";
    } else {
        std::cout << "RSA is invalid!\n";
    }
}