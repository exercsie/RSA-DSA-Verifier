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

}