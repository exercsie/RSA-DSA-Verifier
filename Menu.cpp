#include <iostream>
#include "DSA/DSAMain.h"
#include "RSA/RSAMain.h"
#include "TSA/TSAMain.h"

int main() {
    while(true) {
        std::cout << "\n\nWelcome to asymmetric cryptography!\n";
        std::cout << "1 - DSA verification\n";
        std::cout << "2 - RSA verification\n";
        std::cout << "3 - TSA verification\n";
        std::cout << "4 - Info\n";


        int choice;
        std::cout << "Choose an option: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInvalid input. Try again!\n\n";
            continue;
        } else if (choice < 1 || choice > 4) {
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
            case 3: {
                TSAMain();
                break;
            }
            case 4: {
                std::cout << "\n||DSA||\n\n";
                std::cout << "Find public key:\n";
                std::cout << "y = g^x mod p\n\n";
                std::cout << "Signing a message:\n";
                std::cout << "Choose random k | k subset [1, q-1]\n";
                std::cout << "r = (g^k mod p) mod q\n";
                std::cout << "If r = 0, pick new k\n";
                std::cout << "s = k^-1 *(H(M) + x * r) mod q\n";
                std::cout << "If s = 0, pick new k\n\n";
                std::cout << "Verify the signature:\n";
                std::cout << "w = s^-1 mod q\n";
                std::cout << "u1 = H(M) * w mod q\n";
                std::cout << "u2 = r * w mod q\n";
                std::cout << "v = ((g^u2 * y^u2) mod p) mod q\n";
                std::cout << "if v = r: valid, else invalid\n";

                std::cout << "\n||RSA||\n\n";
                std::cout << "Pick two large primes p and q\n";
                std::cout << "Find modulus: n = p * q\n";
                std::cout << "Complete Euler's totient function: phi(n) = (p-1)(q-1)\n";
                std::cout << "Compute private key d: ed = 1 mod phi(n)\n";
                std::cout << "Encryption: c = m^e mod n\n";
                std::cout << "Decryption: m = c^d mod n\n";
                std::cout << "Check if m equals original plaintext\n";
            }
        }
    }
}