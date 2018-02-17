/*
 *
 * Compute the sum of just the positive integers in an array of integers
 *
 */

#include <iostream>

int iterativeSumPositiveIntegers(int array[], int size);
int recursiveSumPositiveIntegers(int array[], int size);

int main() {

    int ARRAY_LENGTH = 11;
    int ar[ARRAY_LENGTH] = {1, 2, 3, -3, 4, 5, 6, 7, -7, 8, 9};

    std::cout << "THE SUM OF POSITIVE INTEGERS" << std::endl;
    std::cout << "Iterative method: " << iterativeSumPositiveIntegers(ar, ARRAY_LENGTH) << std::endl;
    std::cout << "Recursive method: " << recursiveSumPositiveIntegers(ar, ARRAY_LENGTH) << std::endl;

    return 0;
}

int iterativeSumPositiveIntegers(int array[], int size){
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) sum += array[i];
    }
    return sum;
}

int recursiveSumPositiveIntegers(int array[], int size){


    if (size == 0) return 0;

    int lastNum = 0;
    if (array[size - 1] > 0) lastNum = array[size - 1];
    int allButLastSum = recursiveSumPositiveIntegers(array, size-1);

    return allButLastSum + lastNum;
}