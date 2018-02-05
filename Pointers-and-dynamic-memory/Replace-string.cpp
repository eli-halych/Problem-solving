/*
 *
 * For dynamically allocated strings(type char* as arrayString), create a function 
 * replaceString that takes three parameters, each of type arrayString: source, target, 
 * and replaceText.
 * The function replaces every occurrence of target in source with replaceText.
 * For example, if source points to an array containing abcdabee, target points to
 * ab, and replaceText points to xyz, then when the function ends, source should
 * point to an array containing xyzcdxyzee.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef char * arrayString;

void replaceString(arrayString& source, arrayString target, arrayString replaceText);
void append(arrayString &s, char c);
void concatenate(arrayString &s1, arrayString &s2);
int length(arrayString s);




int main() {

    arrayString string = new char[8];
    string[0] = 'a', string[1] = 'b', string[2] = 'c',
            string[3] = 'd', string[4] = 'e', string[5] = 'f', string[6] = 'g', string[7] = 0;

    replaceString(string, "cfef", "|");

    cout << "New string: ";
    for (int i = 0; i < length(string); ++i) {
        cout << string[i];
    }cout << endl;

    delete[] string; // And here I deallocate this particular string because I no longer need it. Now it is dangling.
    string = NULL; // Not dangling anymore

    return 0;
}




void replaceString(arrayString& source, arrayString target, arrayString replaceText){

    int sourceLength = length(source);
    int targetLength = length(target);
//    int replaceTextLength = length(replaceText);

    arrayString beforeStr = new char[1];
    beforeStr[0] = 0;

    for (int i = 0; i < sourceLength + 1; ++i) {

        if(source[i] == target[0]){
            for (int j = 0; j < targetLength; ++j) {
                    if(source [i+j] != target [j]) { // protecting strings such as abcdefgh from targets like cfff
                        append(beforeStr, source[i]);
                        break;
                    }
                    if (j == targetLength - 1){

                        // let the magic happen here(replace the target string)
                        concatenate(beforeStr, replaceText);
                        i += targetLength - 1;

                    }
            }
        }
        else append(beforeStr, source[i]);
    }

    delete[] source;
    source = beforeStr;

}

void append(arrayString &s, char c)
{
    int oldLength = length(s);

    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++)
    {
        newS[i] = s[i];
    }

    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void concatenate(arrayString &s1, arrayString &s2)
{
    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;


    arrayString newS = new char[s1_NewLength + 1];

    // copy s1 into the beginning of newS
    for (int i = 0; i < s1_OldLength; i++)
    {
        newS[i] = s1[i];
    }
    // add s2 to the end of newS
    for (int i = 0; i < s2_Length; i++)
    {
        newS[s1_OldLength + i] = s2[i];
    }
    // add the null character to end of newS
    newS[s1_NewLength] = 0;

    // deallocate s1 from the heap
    delete[] s1;
    s1 = newS;
}


int length(arrayString s){
    int count = 0;
    while (s[count] != 0) count++;
    return count;
}

