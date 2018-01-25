/*
 *
 * Binary-to-decimal converter and the reverse
 *
 */



#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int b2d(long long int binary);
long long int d2b(int decimal);

int main() {

    cout << "1. Binary to decimal? \n2. Decimal to binary?" << endl;
    int choice;
    cin >> choice;
    cout << endl;


    cout << "Enter a positive number less than 100,000 for D2B converter \nor a binary number max 10^7 digits for B2D converter: ";
    int number;
    cin >> number;
    cout << endl;

    switch (choice){
        case 1: cout << "Decimal representation of " << number << " is " <<b2d(number); break;
        case 2: cout << "Binary representation of " << number << " is " << d2b(number); break;
    }
    cout << endl;

    return 0;
}

long long int d2b(int decimal){

    /*
     * (((((binary += remainder*i))))), where i is * by 10 after each iteration
     *
     * step 1: % by 2(get the remainder)
     * step 2: / by 2(get the new number)
     * step 3: binary += remainder*i
     * step 4: * i by 10; basically 1111 = 1*10^(n-k), where n = 4, k = 1...4
     *
     */

    long long int binary = 0;
    long long int i = 1;
    int remainder;

    while (decimal != 0){

        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder*i;
        i *= 10;

    }

    return binary;

}

int b2d(long long int binary){

    /*
     *
     * (((((decimal += remainder*pow(2, i)))))), where i is ++ on each iteration and i >= 1
     *
     * step 1: % by 10(get the remainder)
     * step 2: / by 10(get the new number)
     * step 3: decimal += remainder*i
     * step 4: i++; basically 9 = 1*2^3 + 0*2^2 + 0*2^1 + 1*2^0;
     *
     *
     */

    int decimal = 0, i = 0, remainder;

    while (binary != 0){

        remainder = binary % 10;
        binary /= 10;
        decimal += remainder*pow(2, i);
        i++;

    }

    return decimal;
}

