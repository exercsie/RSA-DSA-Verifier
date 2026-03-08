#include <iostream>
#include "ModularInverse.h"

long long int modInverse(long long int k, long long int q) {
    for(long long int i = 1; i < q; i++) {
        if((k * i) % q == 1) {
            return i;
        }
    }
    
    return -1;
}