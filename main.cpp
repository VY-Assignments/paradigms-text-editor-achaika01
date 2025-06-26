#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers/TextEditor.h"
#include "Headers/TextClass.h"
#include "Headers/CaesarCipher.h"

int main(int argc, char* argv[]) {
    //TextClass textclass;

    //printf("Commands: 1.Add line 2.Print 3. Tick/Untick 15.End\n");
    //int user_command;
    //do {
    //    cout << "Enter command: ";
    //    cin >> user_command;
    //    textclass.us_command(user_command);
    //} while (user_command != 15);

    //return 0;


     CaesarCipher lib;

    std::string message = "Testing w1th %";
    std::string encrypted = lib.encrypt(message, 1);
    std::string decrypted = lib.decrypt(encrypted, 1);

    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}





//cd .\x64\
//cd .\Debug
//.\TextEditor