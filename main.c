#include <stdio.h>
#include <stdlib.h>
void append_symbols_end();
void resize_text();
int get_free_space_in_arr();
void init_text();
void command(int input);
void print();

int rows = 10;
int colums = 10;

char** text = NULL;

int main(int argc, char* argv[]) {
    printf("Commands:\n1.Append text symbols to the end\n2.Start the new line\n3.Use files to load the information\n4.Use files to save the information\n5.Print the current text to console\n6.Insert the text by line and symbol index\n7.Search\n8.End\n");
    int user_command;
    init_text();
    do {
        printf("Enter command: ");
        scanf_s("%d", &user_command);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        command(user_command);
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
        printf("Command %d Not implemented yet.\n", 3);
        break;
    case 3:
        printf("Command %d Not implemented yet.\n", 3);
        break;
    case 4:
        printf("Command %d Not implemented yet.\n", 4);
        break;
    case 5:
        print();
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
    if (strlen(text_to_app) > get_free_space_in_arr()) {
        resize_text();
    }
    char* poiner = &text[0][0];
    int num = 0;
    int total_ar_size = rows * colums;
    while (num < total_ar_size && poiner[num] != '\0') {
        num++;
    }
    int first_free_row = num / colums;
    int first_free_col = num - (first_free_row * colums);

    for (int i = 0; text_to_app_ptr[i] != '\0' && num + i < total_ar_size; i++) {
        poiner[num + i] = text_to_app_ptr[i];
    }
    if (num + strlen(text_to_app_ptr) < total_ar_size) {
        poiner[num + strlen(text_to_app_ptr)] = '\0';
    }
    if (text_to_app_ptr != text_to_app) {
        free(text_to_app_ptr);
    }
    
}

void resize_text() {
    int new_rows = 2 * rows;
    int new_colums = 2 * colums;
    char** new_text = malloc(new_rows * sizeof(char*));
    for (int i = 0; i < new_rows; i++) {
        new_text[i] = calloc(new_colums, sizeof(char));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            new_text[i][j] = text[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        free(text[i]);
    }
    free(text);
    text = new_text;
    rows = new_rows;
    colums = new_colums;
}

int get_free_space_in_arr() {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            if (text[i][j] != '\0') {
                count++;
            }
            
        }
    }
    return rows*colums - count;
}

void init_text() {
    text = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        text[i] = calloc(colums, sizeof(char));
    }
}

void print() {
    char* ptr = &text[0][0];
    int total_size = rows * colums;
    for (int i = 0; i < total_size && ptr[i] != '\0'; i++) {
        int rw = i / colums;
        int col = i - (rw * colums);
        if (col == colums) {
            printf('\n');
        }
        printf("%c", ptr[i]);
    }
    printf("\n");
}



//cd .\x64\
//cd .\Debug
//.\TextEditor