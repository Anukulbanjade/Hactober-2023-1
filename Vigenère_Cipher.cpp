#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to encrypt a message using the Vigenère Cipher
string vigenereCipherEncrypt(string message, string keyword) {
    string encryptedMessage = "";
    int keyLength = keyword.length();

    for (int i = 0, j = 0; i < message.length(); i++) {
        char c = message[i];
        if (isalpha(c)) {
            char keyChar = keyword[j % keyLength];
            int shift = islower(keyChar) ? keyChar - 'a' : keyChar - 'A';

            char base = islower(c) ? 'a' : 'A';
            encryptedMessage += static_cast<char>((c - base + shift) % 26 + base);
            j++;
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to decrypt a message using the Vigenère Cipher
string vigenereCipherDecrypt(string ciphertext, string keyword) {
    string decryptedMessage = "";
    int keyLength = keyword.length();

    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char keyChar = keyword[j % keyLength];
            int shift = islower(keyChar) ? keyChar - 'a' : keyChar - 'A';

            char base = islower(c) ? 'a' : 'A';
            decryptedMessage += static_cast<char>((c - base - shift + 26) % 26 + base);
            j++;
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    string keyword = "KEY"; // Keyword for the Vigenère Cipher
    string message = "Hello, World!";
    
    string encryptedMessage = vigenereCipherEncrypt(message, keyword);
    cout << "Encrypted: " << encryptedMessage << endl;

    string decryptedMessage = vigenereCipherDecrypt(encryptedMessage, keyword);
    cout << "Decrypted: " << decryptedMessage << endl;

    return 0;
}
