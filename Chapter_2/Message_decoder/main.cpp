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