/*
 *
 * In a substitution cipher problem, all messages are made of
 * uppercase letters and punctuation. The original message is
 * called the plaintext, and you create the ciphertext by substitution
 * each letter with another letter(for example, each C could become an X).
 * For this problem, hard-code a const(!) array of 26 char elements for the cipher,
 * and have your program read a plaintext message and output the equivalent
 * ciphertext.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::toupper;
using std::locale;

string toUpper(string plaintext);
string encode(string plaintext, const char * cipher);
string decode(string plaintext, const char * cipher);

int main() {

    const char * cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";

    string plaintext = "This message is to be encoded...";
//    string plaintext = "abcdefghijklmnopqrstuvwxyz";
    plaintext = toUpper(plaintext);
    cout << "The original message: " << plaintext << endl;

    string encoded = encode(plaintext, cipher);
    cout << "The encoded message: " << encoded << endl;

    string decoded = decode(encoded, cipher);
    cout << "The decoded message: " << decoded << endl;

    return 0;
}

string encode(string plaintext, const char * cipher){

    for (int i = 0; i < plaintext.length(); ++i) {

        // skip chars other than uppercase letters
        if ((plaintext[i] > 64) && (plaintext[i] < 91)) {

            char firstLetter = 'A';
            unsigned int alphaOffset = plaintext[i] - firstLetter;
            plaintext[i] = cipher[alphaOffset];

        }
    }

    return plaintext;
}

string decode(string plaintext, const char * cipher){


    for (int i = 0; i < plaintext.length(); ++i) {

        // skip chars other than uppercase letters
        if ((plaintext[i] > 64) && (plaintext[i] < 91)) {

            char firstLetter = 'A';
            unsigned int alphaOffset = plaintext[i] - firstLetter;

            char temp = plaintext[i];
            int indexInCipher;
            for (int j = 0; j < 26; ++j) {
                if (temp == cipher[j]) {
                    indexInCipher = j;
                    break;
                }
            }

            plaintext[i] = indexInCipher + firstLetter;

        }

    }

    return plaintext;
}

string toUpper(string plaintext){

    locale loc;
    for (string::size_type i = 0; i < plaintext.length(); ++i) {
        plaintext[i] = toupper(plaintext[i], loc);
    }

    return plaintext;
}
