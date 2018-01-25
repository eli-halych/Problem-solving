/*
 *
 * 	The Luhn formula is a widely used system for validating identification numbers.
 * Using the original number, double the value of every other digit. Then add the values of the
 * individual digits together (if a doubled value now has two digits, add the digits * individually).
 * The identification number is valid if the sum is divisible by 10.
 * 	Write a program that takes an identification number of arbitrary length and
 * determines whether the number is valid under the Luhn formula. The program must
 * process each character before reading the next one.
 *
 */

#include <iostream>
using std::cin;
using std::cout;

int doubleDigitValue(int digit){
    int doubledDigit = digit * 2;
    int sum = 0;
    if(doubledDigit >= 10) sum = 1 + (doubledDigit % 10);
    else sum = doubledDigit;
    cout << sum << '\n';
    return sum;
}

int main() {

    char digit;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;

    digit = cin.get();

    // The 10 here means the end of the input, it may differ depending on your system
    while(digit != 10){
        if (position % 2 == 0) { oddLengthChecksum += doubleDigitValue(digit - '0'); evenLengthChecksum += digit -'0';}
        else { oddLengthChecksum += digit -'0'; evenLengthChecksum += doubleDigitValue(digit - '0'); }
        digit = cin.get();
        position++;
    }

    int checksum;
    if ((position - 1) % 2 == 0) checksum = evenLengthChecksum;
    else checksum = oddLengthChecksum;

    cout << "The checksum is " << checksum << '\n';
    if(checksum % 10 == 0) cout << "Valid number" << '\n';
    else cout << "Invalid checksum" << '\n';


    return 0;
}
