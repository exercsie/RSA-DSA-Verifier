#include <iostream>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"
#include "ModularSecondNumPart.h"

int main() {
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
    int n;
    n = p * q;
    std::cout << "n is: " << n << std::endl;

    int phiN;
    phiN = (p-1)*(q-1);
    std::cout << "phi(n) is: " << phiN << std::endl;

    // find private key
    int privateKey, modularSecondNum;
    modularSecondNum = getModularPart(phiN, e);
    privateKey = e * modularSecondNum + phiN * 1;
    int x, y;
    if(privateKey == 1) {
        x = modularSecondNum;
        y = privateKey;
    } 

    privateKey = phiN + modularSecondNum;
    std::cout << "Private key is: " << privateKey << std::endl;
}