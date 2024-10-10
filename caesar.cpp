#include <iostream>
#include <windows.h>
#include <cctype>

using namespace std;

void setcolor(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

string encrypt(const string& text, int shift){
    string encrypted_text;

    for(char i: text){
        if(isalpha(i)){
            char ascii_offset = isupper(i) ? 'A' : 'a';
            encrypted_text += (i - ascii_offset + shift) % 26 + ascii_offset;
        } else{
            encrypted_text += i;
        }
    }

    return encrypted_text;
}

string decrypt(const string& text, int shift){
    string decrypted_text;

    for(char i: text){
        if(isalpha(i)){
            char ascii_offset = isupper(i) ? 'A' : 'a';
            decrypted_text += (i - ascii_offset - shift + 26) % 26 + ascii_offset;
        } else{
            decrypted_text += i;
        }
    }

    return decrypted_text;
}

int main(){
    string caesar_cipher = R"(
   ___                          ___ _      _            
  / __|__ _ ___ ___ __ _ _ _   / __(_)_ __| |_  ___ _ _ 
 | (__/ _` / -_|_-</ _` | '_| | (__| | '_ \ ' \/ -_) '_|
  \___\__,_\___/__/\__,_|_|    \___|_| .__/_||_\___|_|  
                                     |_|                
)";

    setcolor(4);
    cout << caesar_cipher;
    setcolor(7);
    int shift = 3; // default shift is 3
    string msg;

    cout << "\n\n1.Encrypt text\n2.Decrypt text\n";
    cout << "Choose option 1 or 2: ";
    int opt; cin >> opt;
    cin.ignore();

    if(opt == 1){
        cout << "Enter text to be encrypted: ";
        getline(cin, msg);
        cout << "Enter the shift value: "; cin >> shift;
        setcolor(2);
        cout << "\nEncrypted text: ";setcolor(7);cout << encrypt(msg, shift);

    } else{
        cout << "Enter text to be decrypted: ";
        getline(cin, msg);
        cout << "Enter the shift value: "; cin >> shift;
        setcolor(2);
        cout << "\nDecrypted text: ";setcolor(7);cout << decrypt(msg, shift);
    }
}
