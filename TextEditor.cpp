#define _CRT_SECURE_NO_WARNINGS
#include "TextEditor.h"
#include <iostream>

TextEditor::TextEditor() {
    text = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        text[i] = (char*)calloc(colums, sizeof(char));
    }
}

void TextEditor::command(int input) {
    switch (input) {
    case 1: {
        append_symbols_end();
        break;
    }
    case 2:
        start_new_line();
        break;
    case 3: {
        printf("Enter the file name for saving: ");
        int size_fn = 100 * sizeof(char);
        char* file_name = (char*)malloc(size_fn);
        if (file_name == NULL) {
            printf("No file name");
            break;
        }
        fgets(file_name, size_fn, stdin);
        file_name[strcspn(file_name, "\n")] = 0;
        save_to_the_file(file_name);
        free(file_name);
        break;
    }
    case 4: {
        printf("Enter the file name for loading: ");
        int size_l_fn = 100 * sizeof(char);
        char* file_load_name = (char*)malloc(size_l_fn);
        if (file_load_name == NULL) {
            printf("No file name");
            break;
        }
        fgets(file_load_name, size_l_fn, stdin);
        file_load_name[strcspn(file_load_name, "\n")] = 0;
        load_from_file(file_load_name);
        free(file_load_name);
        break;
    }
    case 5:
        print();
        break;
    case 6: {
        int insert_row;
        int insert_col;
        printf("Enter char or word to search: ");
        int size_insert = 20 * sizeof(char);
        char* word_insert = (char*)malloc(size_insert);
        if (word_insert == NULL) {
            printf("No file name");
            return;
        }
        fgets(word_insert, size_insert, stdin);
        word_insert[strcspn(word_insert, "\n")] = 0;
        printf("Enter row: ");
        if (scanf("%d", &insert_row) != 1) {
            printf("Invalid input for row.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            return;
        }
        printf("Enter column: ");
        if (scanf("%d", &insert_col) != 1) {
            printf("Invalid input for row.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            return;
        }
        insert(word_insert, insert_row, insert_col);

          break;
    }
    case 7: {
        printf("Enter char or word to search: ");
        int size_search = 20 * sizeof(char);
        char* word_search = (char*)malloc(size_search);
        if (word_search == NULL) {
            printf("No file name");
            return;
        }
        fgets(word_search, size_search, stdin);
        word_search[strcspn(word_search, "\n")] = 0;
        search(word_search);
        break;
    }
    }
}

void TextEditor::append_symbols_end() {
    int size = 100 * sizeof(char);
    char* text_to_app = (char*)malloc(size);
    text_to_app[0] = '\0';

    printf("Enter text to append: \n");
    fgets(text_to_app, size, stdin);

    for (int i = 0; i < strlen(text_to_app); i++) {
        if (text_to_app[i] == '\n') {
            text_to_app[i] = '\0';
        }
    }

    int len = strlen(text_to_app);
    for (int i = 0; i < len; i++) {
        int row = current_index / colums;
        int col = current_index % colums;
        if (row >= rows || col >= colums) {
            resize_text();
        }
        text[row][col] = text_to_app[i];
        current_index++;
    }
    int row = current_index / colums;
    int col = current_index % colums;
    text[row][col] = '\0';

}

void TextEditor::resize_text() {
    int new_rows = 2 * rows;
    int new_colums = 2 * colums;
    char** new_text = (char**)malloc(new_rows * sizeof(char*));
    for (int i = 0; i < new_rows; i++) {
        new_text[i] = (char*)calloc(new_colums, sizeof(char));
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

int TextEditor::get_free_space_in_text() {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            if (text[i][j] != '\0') {
                count++;
            }

        }
    }
    return rows * colums - count;
}

void TextEditor::print() {
    for (int i = 0; i < current_index; i++) {
        if (text == NULL) {
            printf("No text to print.\n");
            break;
        }
        int row = i / colums;
        int col = i % colums;
        char ch = text[row][col];
        if (ch == '\0') continue;
        printf("%c", ch);
    }
    printf("\n");
}

void TextEditor::start_new_line() {
    start_from_row++;
    if (start_from_row >= rows) {
        resize_text();
    }

    if (current_index < rows * colums) {
        int row = current_index / colums;
        int col = current_index % colums;
        text[row][col] = '\n';
        current_index++;
    }

    current_index = start_from_row * colums;
    printf("New line started.\n");
}

void TextEditor::save_to_the_file(char* file_load_name) {
    FILE* file;
    file = fopen(file_load_name, "a");
    if (file != NULL)
    {
        for (int i = 0; i < current_index; i++) {
            int row = i / colums;
            int col = i % colums;
            char ch = text[row][col];
            if (ch == '\0') continue;
            fputc(ch, file);
            if (col == colums - 1) {
                fputs("\n", file);
            }
        }
        fclose(file);
        for (int i = 0; i < rows; i++) {
            free(text[i]);
        }
        free(text);
        text = NULL;

        printf("Successfuly saved\n");
    }
}

void TextEditor::load_from_file(char* file_name) {
    char ch;
    FILE* file_load;
    file_load = fopen(file_name, "r");
    if (file_load != NULL)
    {
        int size = 10 * sizeof(char);
        char* text_load = (char*)malloc(size);
        int len = 0;
        while ((ch = fgetc(file_load)) != EOF) {
            if (len + 1 >= size) {
                size *= 2;
                char* new_to_load_ptr = (char*)realloc(text_load, size);
                if (new_to_load_ptr == NULL) {
                    printf("Memory reallocation failed");
                    free(text_load);
                    fclose(file_load);
                    return;
                }
                text_load = new_to_load_ptr;
                new_to_load_ptr = NULL;
            }

            text_load[len++] = ch;
        }
        text_load[len] = '\0';

        if (strlen(text_load) + 1 > get_free_space_in_text()) {
            resize_text();
        }

        for (int i = 0; i < len; i++) {
            int row = (current_index + i) / colums;
            int col = (current_index + i) % colums;
            if (row >= rows) {
                resize_text();
            }
            text[row][col] = text_load[i];
        }

        current_index += len;

        free(text_load);
        text_load = NULL;

        fclose(file_load);
        printf("Successfuly loaded\n");
    }
}

void TextEditor::search(char* user_input) {
    for (int i = 0; i <= current_index - strlen(user_input); i++) {
        int match = 1;
        for (int j = 0; j < strlen(user_input); j++) {
            int r = (i + j) / colums;
            int c = (i + j) % colums;
            if (user_input[j] != text[r][c]) {
                match = 0;
                break;
            }

        }
        if (match) {
            int match_row = i / colums;
            int match_col = i % colums;
            printf("Text is present in this position: %d %d\n", match_row, match_col);
        }
        else {
            printf("Not found");
        }
    }
}

void TextEditor::insert(char* user_input, int insert_row, int insert_col) {
    int insert_index = insert_row * colums + insert_col;

    while (insert_index + strlen(user_input) > rows * colums || current_index + strlen(user_input) > rows * colums) {
        resize_text();
    }

    char** new_text = NULL;
    new_text = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        new_text[i] = (char*)calloc(colums, sizeof(char));
    }
    int cur_index = 0;
    for (int i = 0; i < insert_index && i < current_index; i++) {
        int row = cur_index / colums;
        int col = cur_index % colums;
        new_text[row][col] = text[row][col];
        cur_index++;
    }

    for (int i = 0; i < strlen(user_input); i++) {
        int row = cur_index / colums;
        int col = cur_index % colums;
        new_text[row][col] = user_input[i];
        cur_index++;
    }

    for (int i = insert_index; i < current_index; i++) {
        int text_row = i / colums;
        int text_col = i % colums;

        int new_text_row = cur_index / colums;
        int new_text_col = cur_index % colums;

        new_text[new_text_row][new_text_col] = text[text_row][text_col];
        cur_index++;
    }

    for (int i = 0; i < rows; i++) {
        free(text[i]);
    }
    free(text);

    text = new_text;
    current_index = cur_index;
}