#include <iostream>

int getModularPart(int firstNum, int secondNum) {
    if (secondNum == 0) {
        throw std::invalid_argument("[mod ERROR] Your second number cannot be zero.");
    }

    int integerPart = firstNum / secondNum; // 25 / 3 = 8.3333..

    return -integerPart; 
}