#include <iostream>
using namespace std;

class CaesarCipher {
private:
    int shift; 
public:
  
    CaesarCipher(int s) {
        shift = s;
    }

    string encrypt(const string& text) {
        string result = "";
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];

            if (isupper(c)) {
                result += char(int(c + shift - 65) % 26 + 65);
            }
            else if (islower(c)) {
                result += char(int(c + shift - 97) % 26 + 97);
            }
            else {
                result += c;
            }
        }
        return result;
    }

    string decrypt(const string& text) {
        string result = "";
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];

            if (isupper(c)) {
                result += char(int(c - shift - 65 + 26) % 26 + 65); // +26 handles negative shift
            }
          
            else if (islower(c)) {
                result += char(int(c - shift - 97 + 26) % 26 + 97); // +26 handles negative shift
            }
          
            else {
                result += c;
            }
        }
        return result;
    }
};

int main() {
    string text;
    int shift;

    cout << "Enter the text to encrypt: ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;

    CaesarCipher cipher(shift);

    string encryptedText = cipher.encrypt(text);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = cipher.decrypt(encryptedText);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
