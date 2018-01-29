/*
 *
 *   Design your own: Take a problem that you already know how to solve using
 *   an array but that is limited by the size of the array. Rewrite the code to
 *   remove that limitation using a dynamically allocated array.
 *
 */


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int mode(int array[], int ARRAY_LENGTH, int MAX);

int main() {

    int ARRAY_LENGTH = 10; // no longer const in case of dynamically allocated arrays.
    int * numbers = new int[ARRAY_LENGTH];
    int n = 0;

    //Read into array
    cout << "Read in integerss 0-9:" << endl;
    int tmp;
    while (cin >> tmp){

        if (tmp == -1) break; // exit the loop

        numbers[n] = tmp;
        n++;

        if(n >= ARRAY_LENGTH) {
            ARRAY_LENGTH += 10;
            int * temp = new int[ARRAY_LENGTH];
            for (int i = 0; i < n; ++i) {
                temp[i] = numbers[i];
            }
            delete[] numbers; // free old array memory.
            numbers = temp; // now numbers points to new array.
        }
    }


    if (n == 0) cout << "No numbers entered." << endl;
    else cout << "The mode of the array is " << mode(numbers, ARRAY_LENGTH, 10) << endl;

    delete[] numbers;
    numbers = NULL; // to eliminate a possible cross-reference later on

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
