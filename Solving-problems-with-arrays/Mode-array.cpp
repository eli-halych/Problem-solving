/*
 *
 * Write a program that is given an array of integers
 * and determines the mode, which is the number that
 * appears most frequently in the array.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int mode(int array[], int ARRAY_LENGTH, int MAX);

int main() {

    int array[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 3, 2, 6, 8, 9, 4, 5, 5, 5, 6, 7, 10, 9, 4, 6, 7};
    int ARRAY_LENGTH = sizeof(array)/ sizeof(array[0]);

    cout << "The mode of the array is " << mode(array, ARRAY_LENGTH, 10) << endl;

    return 0;
}

int mode(int array[], int ARRAY_LENGTH, int MAX){

    int histogram[MAX];
    int mostFrequent = 0;

    // Fill the histogram with 0s
    for (int i = 0; i < MAX; ++i) {
        histogram[i] = 0;
    }

    // Add all occurrences to the histogram
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        histogram[array[i] - 1]++;
    }

    // Find the highest value of an array, aka an index in the histogram
    for (int i = 0; i < MAX; ++i) {
        if (histogram[i] > histogram[mostFrequent]) mostFrequent = i;
    }
    mostFrequent++;

    // Return the mode of an array
    return mostFrequent;
}
