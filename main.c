#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void append_symbols_end();
void resize_text();
int get_free_space_in_text();
void init_text();
void command(int input);
void print();
void start_new_line();
void save_to_the_file(char* file_name);
void load_from_file(char* file_name);

int rows = 10;
int colums = 10;
int start_from_row = 0;
int current_index = 0;

char** text = NULL;

int main(int argc, char* argv[]) {
    printf("Commands:\n1.Append text symbols to the end\n2.Start the new line\n3.Use files to save the information\n4.Use files to load the information\n5.Print the current text to console\n6.Insert the text by line and symbol index\n7.Search\n8.End\n");
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
        start_new_line();
        break;
    case 3:
        printf("Enter the file name for saving: ");
        int size_fn = 100 * sizeof(char);
        char* file_name = malloc(size_fn);
        fgets(file_name, size_fn, stdin);
        file_name[strcspn(file_name, "\n")] = 0;
        save_to_the_file(file_name);
        free(file_name);
        break;
    case 4:
        printf("Enter the file name for loading: ");
        int size_l_fn = 100 * sizeof(char);
        char* file_load_name = malloc(size_l_fn);
        fgets(file_load_name, size_l_fn, stdin);
        file_load_name[strcspn(file_load_name, "\n")] = 0;
        load_from_file(file_load_name);
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
    //text_to_app
    int size = 100 * sizeof(char);          //do later: more than 100 doesn't work
    char* text_to_app = malloc(size);
    text_to_app[0] = '\0';

    printf("Enter text to append: \n");
    fgets(text_to_app, size, stdin);

    if (strlen(text_to_app) + 1 > size) {
        size *= 2;
        char* new_to_app_ptr = realloc(text_to_app, size);
        if (new_to_app_ptr == NULL) {
            printf("Memory reallocation failed");
            free(text_to_app);
            return;
        }
        text_to_app = new_to_app_ptr;
        new_to_app_ptr = NULL;
    }
    for (int i = 0; i < strlen(text_to_app); i++) {
        if (text_to_app[i] == '\n') {
            text_to_app[i] = '\0';
        }
    }
    //text
    if (strlen(text_to_app) + 1 > get_free_space_in_text()) {
        resize_text();
    }
    char* poiner = &text[0][0];
    int total_ar_size = rows * colums;

    for (int i = 0; text_to_app[i] != '\0' && current_index + i < total_ar_size; i++) {
        poiner[current_index + i] = text_to_app[i];
    }
    current_index += strlen(text_to_app);
    //
    if (current_index < rows * colums) {
        poiner[current_index] = '\0';
    }
    free(text_to_app);
    text_to_app = NULL;
    
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

int get_free_space_in_text() {
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
    for (int i = 0; i < current_index; i++) {
        if (ptr[i] == '\0') {
            continue;
        }
        if ((i + 1) % colums == 0) {
            printf("\n");
        }
        printf("%c", ptr[i]);
    }
    printf("\n");
}

void start_new_line() {
    start_from_row++;
    if (start_from_row >= rows) {
        resize_text();
    }
    char* poiner = &text[0][0];
    int total_ar_size = rows * colums;
    int start_from = start_from_row * colums;

    /*for (int i = current_index; i < (start_from - 1) && i < total_ar_size; i++) {
        poiner[i] = ' ';
    }*/
    if (current_index < total_ar_size) {
        poiner[current_index] = '\n';
        current_index++;
    }
    current_index = start_from;
    printf("New line started.\n");
}

void save_to_the_file(char* file_load_name) {        //чи видаляємо з постійної пам'яті?
    FILE* file;
    file = fopen(file_load_name, "a");
    if (file != NULL)
    {
        char* ptr = &text[0][0];
        for (int i = 0; i < current_index; i++) {
            if (ptr[i] == '\0') {
                continue;
            }
            fputc(ptr[i], file);
            if ((i + 1) % colums == 0) {
                fputs("\n", file);
            }

        }
        fclose(file);
        printf("Successfuly saved\n");
    }
}

void load_from_file(char* file_name) {
    int ch;
    FILE* file_load;
    file_load = fopen(file_name, "r");
    if (file_load != NULL)
    {
        while ((ch = fgetc(file_load)) != EOF) {
            
        }
        fclose(file_load);
        printf("Successfuly saved\n");
    }
}



//cd .\x64\
//cd .\Debug
//.\TextEditor