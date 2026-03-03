#include <iostream>
#include "../ModularExponentiation.h"
#include "../ModularInverse.h"

int main() {
    int p, q, e, m, n;
    std::cout << "Welcome to RSA verifier!\n";
    std::cout << "Please input first prime number, p: ";
    std::cin >> p;
    std::cout << "Please input sencond prime number, q: ";
    std::cin >> q;
    std::cout << "Please input public key, e: ";
    std::cin >> e;
    std::cout << "Please input plain text number, m: ";
    std::cin >> m;
    std::cout << "Please input modulus, n: ";
    std::cin >> n;
}