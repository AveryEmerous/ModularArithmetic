#include <iostream>
#include "lib.h"
#include <cmath>

//Fills the array with the modulus leftover ring.
int fillSet (int *& arr, int mod) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }

    arr = new int[mod];

    for (int i = 0; i < mod; i++) 
        arr[i] = i;

    return 0;
}

//Prints the array in the first parameter with it's adjacent size;
int printSet (int * arr, unsigned size) {
    for (int i = 0; i < size; i++)  {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }

    std::cout << '\n';

    return 0;
}

//Prints a 2D array with capabilities of printing a dynamic one as well.
int print2DSet (int ** arr, unsigned height, unsigned width) { 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) { //Iterates over all of slots to be able to display them on the console.
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n'; //Goes to the next line whenever the previous cycle is completed and with it, the row.
    }
    
    return 0;
}

//Clears the console.
int clrscr () {
    system("clear");
    return 0;
}

//Displays the options for the switch to the user in the console in the main program.
int printOptions () {
    std::cout << "Which option do you wish to execute?:\n";
    std::cout << "0) Exit\n";
    std::cout << "1) Clear screen\n";
    std::cout << "2) Enter modulus\n";
    std::cout << "3) Adding the elements of the leftover ring\n";
    std::cout << "4) Subtraction the elements of the leftover ring\n";
    std::cout << "5) Multiplying the elements of the leftover ring\n";
    std::cout << "6) Dividing the elements of the leftover ring\n";
    std::cout << "7) Fill & print a 2D array with elemets of the\nleftover ring that multiply together with a remainder of one.\n";
    std::cout << "8) Fast power with the first method\n";
    std::cout << "9) Fast power with the second method\n";
    std::cout << "10) Calculate the inverse of a number from the\nleftover ring\n";
    std::cout << "11) Primitive root checker\n";
    std::cout << "12) Find all primitive roots\n";
    std::cout << "13) Discrete logarithm\n";
    //std::cout << "";

    return 0;
}

//Asks the user in the console for an input for the value in the parameters of the function.
//Only accepts positive intiger user inputs.
int queryValue (int val) {
    do {
        std::cin >> val;
        if (val <= 0) std::cout << "Please, enter a valid non-zero intiger.\n";
    } while (val <= 0);

    return val;
}

//Returns the product of a given number being powered up.
int pow (int num, int power) {
    int product = 1;
    for (int i = 0; i < power; i++) {
        product *= num;
    }
    return product;
}

//Converts a number to binary with it being stored in the second parameter.
//Returns the size of the binary array.
int dec2bin (int num, bool *& bin) {
    unsigned size = 0;
    
    for (int i = 0; (num >> i) != 0; i++) {
        size++;
    }

    /* if (bin != nullptr) {
        delete[] bin;
        bin = nullptr;
    } */

    bin = new bool[size];

    for (int i = 0, j = size - 1; (num >> i) != 0; i++, j--) {
        bin[j] = ((num >> i) & 1);
    }

    return size;
}

//Prints on the console all possible additions from the leftover ring.
int addLeftoverRing (int mod) {
    for (int i = 0; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            std::cout << i << " + " << j << " = " << i + j << " % " << mod << " = " << ( i + j ) % mod << '\n'; 
        }
    }

    return 0;
}

//Prints on the console all possible subtractions from the leftover ring.
int subLeftoverRing (int mod) {
    for (int i = 0; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            std::cout << i << " - " << j << " = " << i - j << " % " << mod << " = ";
            if (i - j == 0) std::cout << 0;
            else std::cout << mod + (i - j);
            std::cout << '\n'; 
        }
    }

    return 0;
}

//Prints on the console all possible multiplications from the leftover ring.
int multLeftoverRing (int mod) {
    for (int i = 0; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            std::cout << i << " * " << j << " = " << i * j << " % " << mod << " = " << ( i * j ) % mod << '\n'; 
        }
    }

    return 0;
}

//Displays on the console the divisions of the leftover ring. 
//Starts from 0 until mod - 1;
int divLeftoverRing (int mod) {
    for (int i = 1; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            std::cout << i << " / " << j << " = ";
            if (inverseCalcFirst(j,mod) != -1) std::cout <<  i << " * " << inverseCalcFirst(j,mod) << " =(%" << mod << ")= " << ((i * inverseCalcFirst(j,mod)) % mod);
            else std::cout << -1;
            std::cout << '\n';
        }
    }

    return 0;
}

//Fills a 2D array with a table of all of the possible multiplications of the leftover ring that have a remainder of one.
//Returns the width of the new array.
int fillSetWithRemOne (int **& arr, int mod) {
    unsigned cnt = 0;

    for (int i = 1; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            if ((i * j) % 7 == 1) {
                cnt++;
            }
        }
    }

    int ** tmp = new int*[2];
    for (int i = 0; i < 2; i++) {
        tmp[i] = new int[cnt];
    }

    cnt = 0;

    for (int i = 1; i < mod; i++) {
        for (int j = i; j < mod; j++) {
            if ((i * j) % mod == 1) {
                tmp[0][cnt] = i;
                tmp[1][cnt] = j;
                cnt++;
            }
        }
    }

    if (arr != nullptr) {
        for (int i = 0; i < 2; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    arr = tmp;
    
    return cnt;
}

//Checks if the inputted number is prime. 
bool checkPrime (int query) {
    for (int i = 2; i < sqrt(query); i++) {
        if (query % i == 0) return false;
    }
    
    return true;
}

//Returns the remainder of the inputted powered number without computing the actual number using the first method.
int fastPowerFirst (int base, int power, int mod) {
    int k;
    
    for (k = 2; k < power; k++) {
        if (pow(base,k) % mod == 1) break;
        if (k == power - 1) return -1;
    }

    return (pow(base,power % k) % mod);
    
}

//Returns the remainder of the inputted powered number without computing the actual number using the second method.
int fastPowerSecond(int base, int power, int mod) {
    bool * bin;
    unsigned size = dec2bin(power,bin);
    unsigned tmp = pow(base,2) % mod;
    unsigned product = 1;

    for (int i = size - 1; i >= 0; i--) {
        tmp = ((int)pow(tmp,2) % (int)mod); 
        if (bin[i]) product *= tmp;
    }

    return product % mod;
}

//Returns true, meaning that it is a field, only if the modulus is prime.
//Returns false if it is a ring and not prime.
bool checkField (int mod) {
    if (checkPrime(mod)) return true;
    return false;
}

//Returns the modular inverse of the given input.
int inverseCalcFirst (int num, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((num * i) % mod == 1) return i;
    }
    return -1;
}

//Returns true if the inputted number is a primitive root with the current modulus.
//Returns false otherwise.
bool primitiveRoot (int num, int mod) {
    if (mod % num == 0) return false;
    unsigned tmp_sz = mod - 1;

    int * storage = new int[tmp_sz];

    for (int i = 1, j = 0; i < mod; i++, j++) {
        storage[j] = pow(num,i) % mod;
    }

    //for (int i = 0; i < tmp_sz; i++) std::cout << storage[i]; //debug

    for (int i = 0; i < tmp_sz; i++) {
        for (int j = i + 1; j < tmp_sz; j++) {
            if (storage[i] == storage[j]) {
                //std::cout << "ping!" << i << " | " << j << '\n'; //debug
                return false;
            }
        }
    }

    if (storage != nullptr) {
        delete[] storage;
        storage = nullptr;
    }

    return true;
}

//Returns the descrete logarithm of the inputted base, query and modulus.
//Returns -1 if the operation is not possible.
int dlog (int base, int query, int mod) {
    if (!primitiveRoot(base, mod)) return -1;

    int modulo;

    for (int i = 0; i < mod; i++) {
        modulo = pow(base,i) % mod;
        if (modulo == query) return i;
    }

    return 0;
}

