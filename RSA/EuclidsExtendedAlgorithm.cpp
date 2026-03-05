#include <iostream>
#include <numeric>
#include "../ModularExponentiation.h"
#include "ModularSecondNumPart.h"

int miniEuclidsExtendedAlgorithm(int e, int phiN) {
    if(std::gcd(e, phiN) != 1) {
        std::cout << "e and phiN are not coprime, therefore modular inverse does not exist.\n";
        return 1; 
    }
    
    int x = getModularPart(phiN, e); // 40 / 3 = 13.33, 40 - 13 * 3 = 1
    int d = phiN + x; // 40 + -13 = 27

    if((e * d) % phiN != 1) { // if != 1 then convert ed = 1 mod n to ed = 1 + 40k, then take random k till you get a whole num
        int k = 0;
        while(true) {
            if((1 + phiN * k) % e == 0) {
                return(1 + phiN * k) / e;
            }

            k++;
        }
    }

    return d;
}
