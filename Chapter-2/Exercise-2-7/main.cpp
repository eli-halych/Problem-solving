
/*
 *
 * Base 10 to base N conversions
 *
 */

#include <iostream>


using namespace std;

string value = "";

void convert(int number, int base){

    int remainder;

    // base case
    if(number == 0){
        return;
    }

    remainder = number % base;
    convert(number/base, base); // the recursion will let us get the result backwards
    ::value.append(to_string(remainder)+" ");
};



int main() {

    cout << "Enter a positive base-10 integer: ";
    int number;
    cin >> number;

    cout << "Convert to base: ";
    int base;
    cin >> base;

    convert(number, base);
    cout << "Base-10 number " << number << " to base " << base << ": " << ::value;

    return 0;
}