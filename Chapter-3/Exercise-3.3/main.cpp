/*
 *
 * A bool function that is passed an array and the number of elements in that array
 * and determines whether the data in the array is sorted. This should require only one pass.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isSorted(int array[], int ARRAY_SIZE);


int main() {

    const int ARRAY_SIZE = 10;
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Is the array sorted? " << isSorted(array, ARRAY_SIZE) << endl;

    return 0;
}


bool isSorted(int array[], int ARRAY_SIZE){

    int current = array[0];

    for (int j = 1; j < ARRAY_SIZE; ++j) {
        if(current <= array[j]) array[j] = current;
        else return false;
    }

    return true;
}