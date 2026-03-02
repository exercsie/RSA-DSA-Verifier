#include <iostream>
#include "ModularInverse.h"

int modInverse(int k, int q) {
    for(int i = 1; i < q; i++) {
        if((k * i) % q == 1) {
            return i;
        }
    }
    
    return -1;
}