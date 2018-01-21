
/*
 *
 * Base 10 to base N conversions
 *
 */

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;

string value = "";

void convert(int number, int base){

    int remainder;

    // base case
    if(number == 0){
        return;
    }

    remainder = number % base;
    cout << number << " % " << base << " = " << remainder << endl;
    convert(number/base, base);
    cout << number << " / " << base << " = " << number/base << endl;
    ::value.append(to_string(remainder));
};



int main() {

    cout << "Convert from base(min 2, max 36): ";
    int from;
    cin >> from;

    cout << "To base (min 2, max 36): ";
    int to;
    cin >> to;

    cout << "Enter a positive integer of base " << from << ": ";
    int number;
    cin >> number;

    //convert the base to the one we need to convert from
    convert(to, from);
    cout << "convert base: " << ::value << endl;
    stringstream geek(::value);
    int base;
    geek >> base;
    cout << "Converted base to int: " << base << endl;
    ::value = "";
    convert(number, base); // here the problem
    cout << "convert num: " << ::value << endl;
    cout << "Base-" << from << " number " << number << " to base " << to << ": " << ::value;

    return 0;
}