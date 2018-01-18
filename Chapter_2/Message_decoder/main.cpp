/*
*   Problem: Decode a Message
*
*   A message has been encoded as a text stream that is read character by
*   character. The stream contains a series of comma-delimited integers, each
*   a positive number capable of being represented by a C++ int. However, the
*   character represented by a particular integer depends on the current
*   decoding mode. There are three modes: uppercase, lowercase, and
*   punctuation.
*
*   In uppercase mode, each integer represents an uppercase letter: The
*   integer modulo 27 indicates the letter of the alphabet (where 1 = A
*   and so on). So an input value of 143 in uppercase mode would yeild the
*   letter H because 143 modulo 27 is 8 and H is the eighth letter in the
*   alphabet.
*
*   The lowercase mode works the same but with lowercase lettters; the
*   remainder of dividing the integer by 27 represents the lowercase letter
*   (1 = a and so on). So an input value of 56 in lowercase mode would yeild
*   the letter b because 57 modulo 27 is 2 and b is the second letter in the
*   alphabet.
*
*   In punctuation mode, the integer is instead considered a modulo 9, with
*   the interpretation given by Table 2-3 below. So 19 would yeild an
*   exclamation point because 19 modulo 9 is 1.
*
*   At the beginning of each message, the decoding mode is uppercase letters.
*   Each time a modulo operation (by 27 or 9, depending on the mode) results
*   in 0, the decoding mode switches. If the current mode is uppercase, the
*   mode switches to lowercase letters. If the current mode is lowercase, the
*   mode switches to punctuations, and if it is punctuation, it switches back
*   to uppercase.
*
*   Table 2-3: Punctuation Decoding Mode
*   Number      Symbol
*   1           !
*   2           ?
*   3           ,
*   4           .
*   5           (space)
*   6           ;
*   7           "
*   8           '
*/



#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    /*
     *
     * BREAKING UP THE PROBLEM INTO COMPONENTS SO ALL THE DIRTY WORK GETS DONE EARLY. It's more about problem solving at this stage.
     *
     *
     */

/* Deal with comma */
//    cout << "Enter a sequence of numbers using commas and not using spaces: " << endl;
//    char digitChar;
//
//    do{
//
//        digitChar = cin.get();
//        int number = (digitChar - '0');
//
//        digitChar = cin.get();
//        while ((digitChar != 10) && (digitChar != ',')){
//            number = number * 10 + (digitChar - '0');
//            digitChar = cin.get();
//        }
//
//        cout << "The number is " << number << endl;
//    }while(digitChar !=  10);
//


/* Deal with UPPERCASE */
//    cout << "Enter a number 1-26: ";
//    int number;
//    cin >> number;
//    char outputChar;
//
//    outputChar = (number-1) + 'A';
//    cout << "Equivalent symbol is " << outputChar << endl;

/* Deal with LOWERCASE */
//    cout << "Enter a number 1-26: ";
//    int number;
//    cin >> number;
//    char outputChar;
//
//    outputChar = (number-1) + 'a';
//    cout << "Equivalent symbol is " << outputChar << endl;

/* Deal with PUNCTUATION */
//    cout << "Enter a number 1-8: ";
//    int number;
//    cin >> number;
//    char outputChar;
//
//    switch (number){
//        case 1: outputChar = '!';
//            break;
//        case 2: outputChar = '?';
//            break;
//        case 3: outputChar = ',';
//            break;
//        case 4: outputChar = '.';
//            break;
//        case 5: outputChar = ' ';
//            break;
//        case 6: outputChar = ';';
//            break;
//        case 7: outputChar = '"';
//            break;
//        case 8: outputChar = '\'';
//            break;
//    }
//
//    cout << "Equivalent symbol is " << outputChar << endl;


/* Deal with mode switching */
//    enum modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
//    int number;
//    modeType mode = UPPERCASE;
//    cout << "Enter some numbers ending with -1: ";
//    do{
//        cin >> number;
//        cout << "Number read" << number;
//        switch (mode) {
//            case UPPERCASE:
//                number = number % 27;
//                cout << "Modulo 27: " << number;
//                if (number == 0){
//                    cout << "Switch to LOWERCASE";
//                    mode = LOWERCASE;
//                };
//                break;
//            case LOWERCASE:
//                number = number % 27;
//                cout << "Modulo 27: " << number;
//                if (number == 0){
//                    cout << "Switch to PUNCTUATION";
//                    mode = PUNCTUATION;
//                };
//                break;
//            case PUNCTUATION:
//                number = number % 9;
//                cout << "Modulo 9: " << number;
//                if (number == 0){
//                    cout << "Switch to UPPERCASE";
//                    mode = UPPERCASE;
//                };
//                break;
//        }
//        cout << endl;
//    } while (number != -1);

    /*
     *
     *
     * THE PIECES ARE NOW INTEGRATED BELOW. It's more about Software Engineering now than problem solving.
     *
     *
     */

    char outputChar;
    enum modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
    int number;
    modeType mode = UPPERCASE;
    char digitChar;
    do{

        digitChar = cin.get();
        int number = (digitChar - '0');

        digitChar = cin.get();
        while ((digitChar != 10) && (digitChar != ',')){
            number = number * 10 + (digitChar - '0');
            digitChar = cin.get();
        }
        switch (mode) {
            case UPPERCASE:
                number = number % 27;
                outputChar = number + 'A' - 1;
                if (number == 0){
                    mode = LOWERCASE;
                    continue;
                };
                break;
            case LOWERCASE:
                number = number % 27;
                outputChar = number + 'a' - 1;
                if (number == 0){
                    mode = PUNCTUATION;
                    continue;
                };
                break;
            case PUNCTUATION:
                number = number % 9;
                switch (number){
                    case 1: outputChar = '!';
                        break;
                    case 2: outputChar = '?';
                        break;
                    case 3: outputChar = ',';
                        break;
                    case 4: outputChar = '.';
                        break;
                    case 5: outputChar = ' ';
                        break;
                    case 6: outputChar = ';';
                        break;
                    case 7: outputChar = '"';
                        break;
                    case 8: outputChar = '\'';
                        break;
                }
                if (number == 0) {
                    mode = UPPERCASE;
                    continue;
                }
                break;
        }
        cout << outputChar;
    } while (digitChar != 10);
    cout << endl;

    /*
     * Sample input: 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
     * Output: Right? Yes!
     *
     */


    return 0;
}