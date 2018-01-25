/*
 *
 * Pattern:
 * ########
 * ######
 *   ####
 *   ##
 *
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main() {

    for (int row = 1; row <= 4; ++row) {

        for (int space = 1; space <= (14%row); ++space) {
            cout << ' ';
        }

        for (int hashNum = 1; hashNum <= 2*(5 - row); ++hashNum) {
            cout << '#';
        }

        cout << endl;

    }


    return 0;
}