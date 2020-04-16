#include "lib.h"
#include <iostream>

int main() {
    int mod;
    unsigned choice;
    int * set = nullptr;
    int ** remOneSet = nullptr;
    unsigned widthRemOneSet;

    std::cout << "Enter the modulus of the set:\n";
    mod = queryValue(mod);
    std::cout << '\n';

    std::cout << "Set contents:\n";
    fillSet(set,mod);
    printSet(set,mod);
    std::cout << '\n';
    std::cout << "This set is a ring" << ((checkField(mod) ? " and a field." : ".")) << '\n';
    std::cout << '\n';

    printOptions();

    std::cout << '\n';

    do {
        std::cout << "Option:\n";
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {
            case 0: {
                break;
            }
            case 1: {
                clrscr();
                printOptions();
                std::cout << '\n';
                break;
            }
            case 2: {
                std::cout << "Please eneter the new modulus:\n";
                mod = queryValue(mod);
                std::cout << '\n';
                std::cout << "Set contents:\n";
                fillSet(set,mod);
                printSet(set,mod);
                std::cout << '\n';
                break;
            }
            case 3: {
                std::cout << "All possible additions of this leftover ring:\n";
                addLeftoverRing(mod);
                std::cout << '\n';
                break;
            }
            case 4: {
                std::cout << "All possible subtraction of this leftover ring:\n";
                subLeftoverRing(mod);
                std::cout << '\n';
                break;
            }
            case 5: {
                std::cout << "All possible multiplications of this leftover ring:\n";
                multLeftoverRing(mod);
                std::cout << '\n';
                break;
            }
            case 6: {
                std::cout << "All possible divisions of this leftover ring:\n";
                divLeftoverRing(mod);
                std::cout << '\n';
                break;
            }
            case 7: {
                std::cout << "Multiplication with remnant one:\n";
                widthRemOneSet = fillSetWithRemOne(remOneSet,mod);
                print2DSet(remOneSet,2,widthRemOneSet);
                std::cout << '\n';
                break;
            }
            case 8: {
                int base, power;
                std::cout << "Fastpower with the first method:\n\n";
                std::cout << "Base: ";
                base = queryValue(base);
                std::cout << "Power: ";
                power = queryValue(power);
                std::cout << base << "^" << power << " =(%" << mod << ")" << "= ";
                std::cout << fastPowerFirst(base,power,mod) << "\n\n";
                break;
            }
            case 9: {
                int base, power;
                std::cout << "Fastpower with the second method:\n\n";
                std::cout << "Base: ";
                base = queryValue(base);
                std::cout << "Power: ";
                power = queryValue(power);
                std::cout << base << "^" << power << " =(%" << mod << ")" << "= ";
                std::cout << fastPowerSecond(base,power,mod) << "\n\n";
                break;
            }
            case 10: {
                int input;
                
                do {
                    std::cout << "Enter a number that is within the modular ring: ";
                    std::cin >> input;
                    if (input <= 0 || input >= mod) std::cout << "Please, enter a valid non-zero intiger that is within the ring.\n";
                } while (input <= 0 || input >= mod);

                if (inverseCalcFirst(input,mod) != -1) std::cout << inverseCalcFirst(input,mod) << " is the inverse of " << input << '\n';
                else std::cout << input << " has no inverse.\n";
                std::cout << '\n';
                break;
            }
            case 11: {
                int input;

                do {
                    std::cout << "Number in leftover ring:\n";
                    std::cin >> input;
                    if (input <= 0 || input >= mod) std::cout << "Please, enter a valid non-zero intiger that is within the ring.\n";
                } while (input <= 0 || input >= mod);

                std::cout << input << " is " << ((primitiveRoot(input,mod)) ? "" : "not ") << "primitive root.\n\n";
                break;
            }
            case 12: {
                for (int i = 1; i < mod; i++) {
                    std::cout << i << " is " << ((primitiveRoot(i,mod)) ? "" : "not ") << "primitive root.\n";
                } 
                std::cout << '\n';
                break;
            }
            case 13: {
                int base, query;
                
                do {
                    std::cout << "Base: ";
                    std::cin >> base;
                    if (base <= 0 || base >= mod) std::cout << "Please, enter a valid non-zero intiger that is within the ring.\n";
                } while (base <= 0 || base >= mod);
                
                do {
                    std::cout << "Query: ";
                    std::cin >> query;
                    if (query <= 0 || query >= mod) std::cout << "Please, enter a valid non-zero intiger that is within the ring.\n";
                } while (query <= 0 || query >= mod);

                std::cout << '\n' << "dlog(" << base << ")" << query << " =(%" << mod << ")= " << dlog(base,query,mod) << "\n\n";
                break;
            }
            default: {
                std::cout << "Please, enter a valid non-zero intiger from the given options.\n";
                break;
            }
        }

    } while (choice);

    if (set != nullptr) {
        delete[] set;
        set = nullptr;
    }

    if (remOneSet != nullptr) {
        for (int i = 0; i < widthRemOneSet; i++)
            delete[] remOneSet[i];
        remOneSet = nullptr;
    }

    return 0;
}