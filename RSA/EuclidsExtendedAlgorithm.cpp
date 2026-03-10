#include <iostream>
#include <numeric>
#include "../ModularExponentiation.h"
#include "ModularSecondNumPart.h"

long long int miniEuclidsExtendedAlgorithm(long long int e, long long int phiN) {
    if(std::gcd(e, phiN) != 1) {
        return -1; 
    }

    long long int k = 1;

    while(true) {
        long long int numerator;
        numerator = 1 + phiN * k;

        if(numerator % e == 0) {
            long long int d;
            d = numerator / e;

            if((e * d) % phiN == 1) {
                return d;
            }
        }

        k++;
    }
}
