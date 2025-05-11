#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLUMS 10

char text[ROWS][COLUMS] = { 0 };
void command(int input);
void append_symbols_end();
void resize_text();

int main(int argc, char* argv[]) {
    printf("Commands:\n1.Append text symbols to the end\n2.Start the new line\n3.Use files to load the information\n4.Use files to save the information\n5.Print the current text to console\n6.Insert the text by line and symbol index\n7.Search\n8.End\n");
    int user_command;
    do {
        printf("Enter command: ");
        scanf_s("%d", &user_command);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        command(user_command);
        if (user_command == 1) {
            print_text();
        }
    } while (user_command != 8);


    return 0;
}

void command(int input) {
    switch (input) {
    case 1: {
        append_symbols_end();
        break;
    }
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

void append_symbols_end() {
    char text_to_app[100];
    char* text_to_app_ptr = text_to_app;
    printf("Enter text to append: \n");
    fgets(text_to_app, sizeof(text_to_app), stdin);
    int text_has_right_size = 0;
    if (strlen(text_to_app) < sizeof(text_to_app)) {
        char* new_to_app_ptr = calloc(1, (strlen(text_to_app) + 1));
        strcpy(new_to_app_ptr, text_to_app_ptr);
        text_to_app_ptr = new_to_app_ptr;
    }
    for (int i = 0; i < strlen(text_to_app_ptr); i++) {
        if (text_to_app_ptr[i] == '\n') {
            text_to_app_ptr[i] = '\0';
            text_has_right_size = 1;
        }
    }
    char* poiner = &text[0][0];
    int total_ar_size = ROWS * COLUMS;
    int num = 0;
    while (num < total_ar_size && poiner[num] != '\0') {
        num++;
    }
    int first_free_row = num / COLUMS;
    int first_free_col = num - (first_free_row * COLUMS);

    for (int i = 0; i <= total_ar_size; i++) {
        if (num + i >= total_ar_size) break;
        poiner[num + i] = text_to_app_ptr[i];
    }

    if (text_to_app_ptr != text_to_app) {
        free(text_to_app_ptr);
    }
    
}

void resize_text() {

}



//cd .\x64\
//cd .\Debug
//.\TextEditor