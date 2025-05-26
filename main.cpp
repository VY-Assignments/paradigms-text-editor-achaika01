#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TextEditor.h"
using namespace std;

int main(int argc, char* argv[]) {
    printf("Commands:\n1.Append text symbols to the end\n2.Start the new line\n3.Use files to save the information\n4.Use files to load the information\n5.Print the current text to console\n6.Insert the text by line and symbol index\n7.Search\n8.Delete\n9.Undo\n10.Redo\n11.Cut\n12.Paste\n13.Copy\n14.Insert with replacement\n15.End\n");
    int user_command;
    TextEditor text_editor;
    do {
        printf("Enter command: ");
        scanf_s("%d", &user_command);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        text_editor.command(user_command);
    } while (user_command != 15);


    return 0;
}





//cd .\x64\
//cd .\Debug
//.\TextEditor