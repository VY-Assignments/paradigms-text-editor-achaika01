#include <stdio.h>
void command(int input) {
    switch (input) {
    case 1:
        printf("Command %d Not implemented yet.\n", 1);
        break;
    case 2:
        printf("Command %d Not implemented yet.\n", 2);
        break;
    case 3:
        printf("Command %d Not implemented yet.\n", 3);
        break;
    case 4:
        printf("Command %d Not implemented yet.\n", 4);
        break;
    case 5:
        printf("Command %d Not implemented yet.\n", 5);
        break;
    case 6:
        printf("Command %d Not implemented yet.\n", 6);
        break;
    case 7:
        printf("Command %d Not implemented yet.\n", 7);
        break;
    }
}

int main(int argc, char* argv[]) {
    printf("Commands:\n1.Append text symbols to the end\n2.Start the new line\n3.Use files to load the information\n4.Use files to save the information\n5.Print the current text to console\n6.Insert the text by line and symbol index\n7.Search\n8.End\n");
    printf("Enter command: ");
    int user_command;
    scanf_s("%d", &user_command);
    command(user_command);
    while (user_command != 8) {
        printf("Enter command: ");
        scanf_s("%d", &user_command);
        command(user_command);
    }
    
    return 0;
}


//cd .\x64\
//cd .\Debug
//.\TextEditor