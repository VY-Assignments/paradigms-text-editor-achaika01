#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Headers/TextEditor.h"
#include "Headers/TextClass.h"
using namespace std;

int main(int argc, char* argv[]) {
    TextClass textclass;

    printf("Commands: 1.Add line 2.Print 15.End\n");
    int user_command;
    do {
        cout << "Enter command: ";
        cin >> user_command;
        textclass.us_command(user_command);
    } while (user_command != 15);

    return 0;
}





//cd .\x64\
//cd .\Debug
//.\TextEditor