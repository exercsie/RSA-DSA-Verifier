#include <iostream>
#include "DSA/DSAMain.h"
#include "RSA/RSAMain.h"

int main() {
    while(true) {
        std::cout << "\n\nWelcome to asymmetric cryptography!\n";
        std::cout << "1 - DSA verification\n";
        std::cout << "2 - RSA verification\n";
        std::cout << "3 - Info\n";


        int choice;
        std::cout << "Choose an option: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInvalid input. Try again!\n\n";
            continue;
        } else if (choice < 1 || choice > 3) {
            std::cout << "\nInvalid choice. Try again!\n\n";
        }

        switch(choice) {
            case 1: {
                DSAMain();
                break;
            }
            case 2: {
                RSAMain();
                break;
            }
        }
    }
}