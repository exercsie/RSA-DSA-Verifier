#include "ComputeR.h"
#include "../ModularExponentiation.h"

int computeR(int g, int k, int p, int q) {
    return modExp(g, k, p) % q;
}