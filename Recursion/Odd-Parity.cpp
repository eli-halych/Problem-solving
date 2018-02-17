/*
 *
 * Check if a number of 1's in a binary string is odd.
 * Return TRUE if it is, return FALSE if it is not.
 *
 */

#include <iostream>

using std::string;

bool iterativeOddParity(string str);
bool recursiveOddParity(string& str, int size);
int length(string s); // reused from previous chapters

int main() {

    string binary = "01011"; // five 1's
    int size = length(binary);

    std::cout << "IS THERE ODD PARITY?" << std::endl;
    std::cout << "Iterative method: " << iterativeOddParity(binary) << std::endl;
    std::cout << "Recursive method: " << recursiveOddParity(binary, size) << std::endl;

    return 0;
}

bool iterativeOddParity(string str){
    int sum = 0;
    for (char& c : str) {
        if (c == '1') sum++;
    }
    return sum % 2 != 0;
}

bool recursiveOddParity(string& str, int size){

    // return false <- allButLast is even or NULL
    // return true <- allButLast is odd

    // even + odd = odd; odd + even = odd;   => true
    // even + even = odd; even + even = even;   => false
    // XOR is what needed


    if (size == 0) return false;
    bool allButLast = recursiveOddParity(str, size - 1);

    return !(allButLast == (str[size-1] == '1')); // XOR

}

int length(string s){
    int count = 0;
    while (s[count] != 0) count++;
    return count;
}