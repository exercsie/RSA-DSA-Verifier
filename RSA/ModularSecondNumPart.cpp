#include <iostream>

long long int getModularPart(long long int firstNum, long long int secondNum) {
    if (secondNum == 0) {
        throw std::invalid_argument("[mod ERROR] Your second number cannot be zero.");
    }

    long long int integerPart = firstNum / secondNum; // 25 / 3 = 8.3333..

    return -integerPart; 
}