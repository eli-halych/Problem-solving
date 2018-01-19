#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    //upper half
    for (int row = 1; row <= 4; ++row) {

//        for (int space = 1; space <= ; ++space) {
//            cout << ' ';
//        }

        for (int hash = 1; hash <= 2 + 2*(row - 1); ++hash) {
            cout << '#';
        }

        cout << endl;
    }

    //lower half
    for (int row = 1; row <= 4; ++row) {

//        for (int space = 1; space <= 0; ++space) {
//            cout << ' ';
//        }

        for (int hash = 1; hash <= 8 - 2*(row - 1); ++hash) {
            cout << '#';
        }

        cout << endl;
    }

    return 0;
}