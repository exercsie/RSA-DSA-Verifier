#include <iostream>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"

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

}