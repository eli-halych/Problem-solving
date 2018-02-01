/*
 *
 * For dynamically allocated strings(type char* as arrayString), create a function replaceString that takes
 * three parameters, each of type arrayString: source, target, and replaceText.
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
void append(arrayString &s, int length, arrayString newPiece);
int length(arrayString s);




int main() {

    arrayString string = new char[9];
    string[0] = 't', string[1] = 'e', string[2] = 's',
            string[3] = 't', string[4] = 'e', string[5] = 's',
            string[5] = 't', string[6] = 'e', string[7] = 's',
            string[8] = 0;
    replaceString(string, "te", "-");

    for (int i = 0; i < length(string); ++i) {
        cout << string[i];
    }cout << endl;

    delete[] string; // And here I deallocate this particular string because I no longer need it. Now it is dangling.
    string = NULL; // Not dangling anymore

//    delete[] newString;
//             newString = NULL;

    return 0;
}




void replaceString(arrayString& source, arrayString target, arrayString replaceText){

    int sourceLength = length(source);
    int targetLength = length(target);
    int replaceTextLength = length(replaceText);

    for (int i = 0; i < sourceLength + 1; ++i) {
        for (int j = 0; j < targetLength; ++j) {
            if (source[i+j] == target[j]) {
                if (j == targetLength-1) { //here's the final point if the target has been found

                    //define lengths for the before and after parts of target
                    int beforeLength = i;
                    int afterLength = sourceLength - targetLength - beforeLength;


                    // The before and after arrays
                    arrayString beforeAndReplaceStr = new char[beforeLength + replaceTextLength + afterLength];
                    arrayString afterStr = new char[afterLength];
                    //
                    for (int c = 0; c < beforeLength; ++c) {
                        beforeAndReplaceStr[c] = source[c];
                    }
                    for (int c = (beforeLength + targetLength) - 1; c < sourceLength; ++c) {
                        afterStr[c] = source[c];
                    }


                    // Append all parts
                    append(beforeAndReplaceStr, beforeLength, replaceText);
                    append(beforeAndReplaceStr, beforeLength+replaceTextLength, afterStr);

                    // Delete references
                    delete[] source;
                    delete[] afterStr;
                    source = beforeAndReplaceStr;


                }
                continue;
            }
            break;
        }
    }

}

void append(arrayString &s, int s_length, arrayString newPiece) {
    int newPieceLength = length(newPiece);

    for (int i = s_length, j = 0; j < newPieceLength; i++, j++)
    {
        s[i] = newPiece[j];
    }

}

int length(arrayString s){
    int count = 0;
    while (s[count] != 0) count++;
    return count;
}