/*
 *
 *   For our dynamically allocated strings, create a function substring that
 *   takes three parameters: an arrayString, a starting position integer, and
 *   an integer length of characters. The function returns a pointer to a new
 *   dynamically allocated string array. This string array contains the
 *   characters in the original string, starting at the specified position
 *   for the specified length. The original string is unaffected by the
 *   operation. So if the original string abcdefg, the position was 3, and the
 *   length was 4, then the new string would contain cdef.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef char * arrayString;

arrayString substring(arrayString& s, int start, int length);
int length(arrayString s);




int main() {

    arrayString string = new char[5];
    string[0] = 't', string[1] = 'e', string[2] = 's', string[3] = 't', string[4] = 0;
    arrayString newString = substring(string, 2, 4); // (string, startIndex, newLength)

    for (int i = 0; i < length(newString); ++i) {
        cout << newString[i];
    }cout << endl;

    delete[] string; // And here I deallocate this particular string because I no longer need it. Now it is dangling.
             string = NULL; // Not dangling anymore
    delete[] newString;
             newString = NULL;

    return 0;
}




arrayString substring(arrayString& s, int start, int length){

    arrayString newString = new char[length+1]; // +1 because we need to add NULL at the end

    for (int i = 0; i < length; ++i) {
        newString[i] = s[start+i];
    }

    newString[length] = 0; // add NULL to the end
    /*
     * I think delete[] necessary when there's no need to keep an array on the heap.
     * In this case there're 2 different variables allocated in the memory and I wish to keep them
     * to use later
     */
//    delete[] s;
//    s = NULL;
    return newString;
}


int length(arrayString s){
    int count = 0;
    while (s[count] != 0) count++;
    return count;
}
