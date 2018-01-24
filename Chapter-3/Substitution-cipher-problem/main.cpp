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

void encode(string plaintext, const char * cipher);

int main() {

    const char * cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string plaintext = "This message is to be encoded...";

    encode(plaintext, cipher);

    return 0;
}

void encode(string plaintext, const char * cipher){

    locale loc;
    for (string::size_type i = 0; i < plaintext.length(); ++i) {

        plaintext[i] = toupper(plaintext[i], loc);

        // skip chars other than uppercase letters
        if ((plaintext[i] > 64) && (plaintext[i] < 91)) {
            plaintext[i] = cipher[plaintext[i] - 'A' + 1];
        }
    }

    cout << plaintext;
}