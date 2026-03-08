#include "ComputeR.h"
#include "../ModularExponentiation.h"

long long int computeR(long long int g, long long int k, long long int p, long long int q) {
    return modExp(g, k, p) % q;
}