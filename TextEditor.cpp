//#define _CRT_SECURE_NO_WARNINGS
//#include "Headers/TextEditor.h"
//#include "Headers/Line.h"
//#include "Headers/TextLine.h"
//#include <iostream>
//#include <stdlib.h>
//#include <stack>
//using namespace std;
//
//TextEditor::TextEditor() {
//
//}

//void TextEditor::resize_buffer() {
//    char* temp = (char*)realloc(buffer.buffer_array, buffer.size * 2 * sizeof(char));
//    if (temp != NULL) {
//        buffer.buffer_array = temp;
//        buffer.size *= 2;
//    }
//    else {
//        printf("memory allocation failed");
//    }
//}
//
//void TextEditor::command(int input) {
//    switch (input) {
//    case 1: {
//        append_symbols_end();
//        break;
//    }
//    case 2:
//        start_new_line();
//        break;
//    case 3: {
//        printf("Enter the file name for saving: ");
//        int size_fn = 100 * sizeof(char);
//        char* file_name = (char*)malloc(size_fn);
//        if (file_name == NULL) {
//            printf("No file name");
//            break;
//        }
//        fgets(file_name, size_fn, stdin);
//        file_name[strcspn(file_name, "\n")] = 0;
//        save_to_the_file(file_name);
//        free(file_name);
//        break;
//    }
//    case 4: {
//        printf("Enter the file name for loading: ");
//        int size_l_fn = 100 * sizeof(char);
//        char* file_load_name = (char*)malloc(size_l_fn);
//        if (file_load_name == NULL) {
//            printf("No file name");
//            break;
//        }
//        fgets(file_load_name, size_l_fn, stdin);
//        file_load_name[strcspn(file_load_name, "\n")] = 0;
//        load_from_file(file_load_name);
//        free(file_load_name);
//        break;
//    }
//    case 5:
//        print();
//        break;
//    case 6: {
//        int insert_row;
//        int insert_col;
//        printf("Enter char or word to insert: ");
//        int size_insert = 20 * sizeof(char);
//        char* word_insert = (char*)malloc(size_insert);
//        if (word_insert == NULL) {
//            printf("No file name");
//            return;
//        }
//        fgets(word_insert, size_insert, stdin);
//        word_insert[strcspn(word_insert, "\n")] = 0;
//        printf("Enter row: ");
//        if (scanf("%d", &insert_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &insert_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        insert(word_insert, insert_row, insert_col);
//
//          break;
//    }
//    case 7: {
//        printf("Enter char or word to search: ");
//        int size_search = 20 * sizeof(char);
//        char* word_search = (char*)malloc(size_search);
//        if (word_search == NULL) {
//            printf("No file name");
//            return;
//        }
//        fgets(word_search, size_search, stdin);
//        word_search[strcspn(word_search, "\n")] = 0;
//        search(word_search);
//        break;
//    }
//    case 8: {
//        int insert_row;
//        int insert_col;
//        int number_of_symb;
//        printf("Enter row: ");
//        if (scanf("%d", &insert_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &insert_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter number of symbols: ");
//        if (scanf("%d", &number_of_symb) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        delete_symb(insert_row, insert_col, number_of_symb);
//        break;
//    }
//    case 9:
//        undo();
//        break;
//    case 10:
//        redo();
//        break;
//    case 11: {
//        int cut_row;
//        int cut_col;
//        int number_of_symb;
//        printf("Enter row: ");
//        if (scanf("%d", &cut_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &cut_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter number of symbols: ");
//        if (scanf("%d", &number_of_symb) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        cut(cut_row, cut_col, number_of_symb);
//        break;
//    }
//    case 12: {
//        int paste_row;
//        int paste_col;
//        printf("Enter row: ");
//        if (scanf("%d", &paste_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &paste_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        paste(paste_row, paste_col);
//        break;
//    }
//        
//    case 13: {
//        int copy_row;
//        int copy_col;
//        int number_of_symb;
//        printf("Enter row: ");
//        if (scanf("%d", &copy_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &copy_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter number of symbols: ");
//        if (scanf("%d", &number_of_symb) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        copy(copy_row, copy_col, number_of_symb);
//        break;
//    }
//        
//    case 14: {
//        int insert_row;
//        int insert_col;
//        printf("Enter char or word to insert: ");
//        int size_insert = 20 * sizeof(char);
//        char* word_insert = (char*)malloc(size_insert);
//        if (word_insert == NULL) {
//            printf("No file name");
//            return;
//        }
//        fgets(word_insert, size_insert, stdin);
//        word_insert[strcspn(word_insert, "\n")] = 0;
//        printf("Enter row: ");
//        if (scanf("%d", &insert_row) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        printf("Enter column: ");
//        if (scanf("%d", &insert_col) != 1) {
//            printf("Invalid input for row.\n");
//            int ch;
//            while ((ch = getchar()) != '\n' && ch != EOF);
//            return;
//        }
//        insert_with_replacement(word_insert, insert_row, insert_col);
//
//        break;
//    }
//    }
//}
//
//void TextEditor::append_symbols_end() {
//    int size = 100 * sizeof(char);
//    char* text_to_app = (char*)malloc(size);
//    text_to_app[0] = '\0';
//    int old_row = current_index / colums;
//    int old_col = current_index % colums;
//
//    printf("Enter text to append: \n");
//    fgets(text_to_app, size, stdin);
//
//    for (int i = 0; i < strlen(text_to_app); i++) {
//        if (text_to_app[i] == '\n') {
//            text_to_app[i] = '\0';
//        }
//    }
//
//    int len = strlen(text_to_app);
//    for (int i = 0; i < len; i++) {
//        int row = current_index / colums;
//        int col = current_index % colums;
//        if (row >= rows || col >= colums) {
//            resize_text();
//        }
//        text[row][col] = text_to_app[i];
//        current_index++;
//    }
//    int row = current_index / colums;
//    int col = current_index % colums;
//    text[row][col] = '\0';
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::DELETE, old_row, old_col, strlen(text_to_app), text_to_app);
//        while (!redo_stack.empty()) redo_stack.pop();
//    }
//    
//}
//
//void TextEditor::resize_text() {
//    int new_rows = 2 * rows;
//    int new_colums = 2 * colums;
//    char** new_text = (char**)malloc(new_rows * sizeof(char*));
//    for (int i = 0; i < new_rows; i++) {
//        new_text[i] = (char*)calloc(new_colums, sizeof(char));
//    }
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < colums; j++) {
//            new_text[i][j] = text[i][j];
//        }
//    }
//    for (int i = 0; i < rows; i++) {
//        free(text[i]);
//    }
//    free(text);
//    text = new_text;
//    rows = new_rows;
//    colums = new_colums;
//}
//
//int TextEditor::get_free_space_in_text() {
//    int count = 0;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < colums; j++) {
//            if (text[i][j] != '\0') {
//                count++;
//            }
//
//        }
//    }
//    return rows * colums - count;
//}
//
//void TextEditor::print() {
//    for (int i = 0; i < current_index; i++) {
//        if (text == NULL) {
//            printf("No text to print.\n");
//            break;
//        }
//        int row = i / colums;
//        int col = i % colums;
//        char ch = text[row][col];
//        if (ch == '\0') continue;
//        printf("%c", ch);
//    }
//    printf("\n");
//}
//
//void TextEditor::start_new_line() {         //undo окремий кейс
//    start_from_row++;
//    if (start_from_row >= rows) {
//        resize_text();
//    }
//
//    if (current_index < rows * colums) {
//        int row = current_index / colums;
//        int col = current_index % colums;
//        text[row][col] = '\n';
//        current_index++;
//    }
//
//    current_index = start_from_row * colums;
//    printf("New line started.\n");
//}
//
//void TextEditor::save_to_the_file(char* file_load_name) {
//    FILE* file;
//    file = fopen(file_load_name, "a");
//    if (file != NULL)
//    {
//        for (int i = 0; i < current_index; i++) {
//            int row = i / colums;
//            int col = i % colums;
//            char ch = text[row][col];
//            if (ch == '\0') continue;
//            fputc(ch, file);
//            if (col == colums - 1) {
//                fputs("\n", file);
//            }
//        }
//        fclose(file);
//        for (int i = 0; i < rows; i++) {
//            free(text[i]);
//        }
//        free(text);
//        text = NULL;
//
//        printf("Successfuly saved\n");
//    }
//}
//
//void TextEditor::load_from_file(char* file_name) {
//    char ch;
//    FILE* file_load;
//    file_load = fopen(file_name, "r");
//    if (file_load != NULL)
//    {
//        int size = 10 * sizeof(char);
//        char* text_load = (char*)malloc(size);
//        int len = 0;
//        while ((ch = fgetc(file_load)) != EOF) {
//            if (len + 1 >= size) {
//                size *= 2;
//                char* new_to_load_ptr = (char*)realloc(text_load, size);
//                if (new_to_load_ptr == NULL) {
//                    printf("Memory reallocation failed");
//                    free(text_load);
//                    fclose(file_load);
//                    return;
//                }
//                text_load = new_to_load_ptr;
//                new_to_load_ptr = NULL;
//            }
//
//            text_load[len++] = ch;
//        }
//        text_load[len] = '\0';
//
//        if (strlen(text_load) + 1 > get_free_space_in_text()) {
//            resize_text();
//        }
//
//        for (int i = 0; i < len; i++) {
//            int row = (current_index + i) / colums;
//            int col = (current_index + i) % colums;
//            if (row >= rows) {
//                resize_text();
//            }
//            text[row][col] = text_load[i];
//        }
//
//        current_index += len;
//
//        free(text_load);
//        text_load = NULL;
//
//        fclose(file_load);
//        printf("Successfuly loaded\n");
//    }
//}
//
//void TextEditor::search(char* user_input) {
//    for (int i = 0; i <= current_index - strlen(user_input); i++) {
//        int match = 1;
//        for (int j = 0; j < strlen(user_input); j++) {
//            int r = (i + j) / colums;
//            int c = (i + j) % colums;
//            if (user_input[j] != text[r][c]) {
//                match = 0;
//                break;
//            }
//
//        }
//        if (match) {
//            int match_row = i / colums;
//            int match_col = i % colums;
//            printf("Text is present in this position: %d %d\n", match_row, match_col);
//        }
//        else {
//            printf("Not found");
//        }
//    }
//}
//
//void TextEditor::insert(char* user_input, int insert_row, int insert_col) {
//    int insert_index = insert_row * colums + insert_col;
//
//    while (insert_index + strlen(user_input) > rows * colums || current_index + strlen(user_input) > rows * colums) {
//        resize_text();
//    }
//
//    char** new_text = NULL;
//    new_text = (char**)malloc(rows * sizeof(char*));
//    for (int i = 0; i < rows; i++) {
//        new_text[i] = (char*)calloc(colums, sizeof(char));
//    }
//    int cur_index = 0;
//    for (int i = 0; i < insert_index && i < current_index; i++) {
//        int row = cur_index / colums;
//        int col = cur_index % colums;
//        new_text[row][col] = text[row][col];
//        cur_index++;
//    }
//
//    for (int i = 0; i < strlen(user_input); i++) {
//        int row = cur_index / colums;
//        int col = cur_index % colums;
//        new_text[row][col] = user_input[i];
//        cur_index++;
//    }
//
//    for (int i = insert_index; i < current_index; i++) {
//        int text_row = i / colums;
//        int text_col = i % colums;
//
//        int new_text_row = cur_index / colums;
//        int new_text_col = cur_index % colums;
//
//        new_text[new_text_row][new_text_col] = text[text_row][text_col];
//        cur_index++;
//    }
//
//    for (int i = 0; i < rows; i++) {
//        free(text[i]);
//    }
//    free(text);
//
//    text = new_text;
//    current_index = cur_index;
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::DELETE, insert_row, insert_col, strlen(user_input));
//        while (!redo_stack.empty()) redo_stack.pop();
//    }
//    
//}
//
//void TextEditor::insert_with_replacement(char* user_input, int insert_row, int insert_col) {
//    int insert_index = insert_row * colums + insert_col;
//
//    char* deleted_text = (char*)malloc(strlen(user_input) + 1);
//    for (int i = 0; i < strlen(user_input); i++) {
//        int r = (insert_index + i) / colums;
//        int c = (insert_index + i) % colums;
//        deleted_text[i] = text[r][c];
//    }
//    deleted_text[strlen(user_input)] = '\0';
//
//    while (insert_index + strlen(user_input) > rows * colums || current_index + strlen(user_input) > rows * colums) {
//        resize_text();
//    }
//    char** new_text = NULL;
//    new_text = (char**)malloc(rows * sizeof(char*));
//    for (int i = 0; i < rows; i++) {
//        new_text[i] = (char*)calloc(colums, sizeof(char));
//    }
//    int cur_index = 0;
//    for (int i = 0; i < insert_index && i < current_index; i++) {
//        int row = cur_index / colums;
//        int col = cur_index % colums;
//        new_text[row][col] = text[row][col];
//        cur_index++;
//    }
//
//    for (int i = 0; i < strlen(user_input); i++) {
//        int row = cur_index / colums;
//        int col = cur_index % colums;
//        new_text[row][col] = user_input[i];
//        cur_index++;
//    }
//    for (int i = insert_index; i < current_index; i++) {
//        int text_row = i / colums;
//        int text_col = i % colums;
//
//        int new_text_row = cur_index / colums;
//        int new_text_col = cur_index % colums;
//
//        new_text[new_text_row][new_text_col] = text[new_text_row][new_text_col];
//        cur_index++;
//    }
//
//    for (int i = 0; i < rows; i++) {
//        free(text[i]);
//    }
//    free(text);
//
//    text = new_text;
//    current_index = cur_index;
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::DELETEINSERT, insert_row, insert_col, strlen(deleted_text), deleted_text);
//        while (!redo_stack.empty()) redo_stack.pop();
//    }
//    
//}
//
//void TextEditor::delete_symb(int delete_row, int delete_col, int number_symbols) {
//    int delete_index = delete_row * colums + delete_col;
//
//    char* deleted_text = (char*)malloc(number_symbols + 1);
//    for (int i = 0; i < number_symbols; i++) {
//        int r = (delete_index + i) / colums;
//        int c = (delete_index + i) % colums;
//        deleted_text[i] = text[r][c];
//    }
//    deleted_text[number_symbols] = '\0';
//
//    char** new_text = NULL;
//    new_text = (char**)malloc(rows * sizeof(char*));
//    for (int i = 0; i < rows; i++) {
//        new_text[i] = (char*)calloc(colums, sizeof(char));
//    }
//    int cur_index = 0;
//    for (int i = 0; i < delete_index && i < current_index; i++) {
//        int row = i / colums;
//        int col = i % colums;
//        new_text[row][col] = text[row][col];
//        cur_index++;
//    }
//    for (int i = delete_index; i < current_index; i++) {
//        int new_text_row = i / colums;
//        int new_text_col = i % colums;
//
//        if (i + number_symbols >= rows * colums) break;
//
//        int old_text_row = (i + number_symbols) / colums;
//        int old_text_col = (i + number_symbols) % colums;
//
//        new_text[new_text_row][new_text_col] = text[old_text_row][old_text_col];
//        cur_index++;
//    }
//    for (int i = 0; i < rows; i++) {
//        free(text[i]);
//    }
//    free(text);
//
//    text = new_text;
//    current_index = cur_index;
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::INSERT, delete_row, delete_col, number_symbols, deleted_text);
//        while (!redo_stack.empty()) redo_stack.pop();
//    }
//    
//}
//
//void TextEditor::cut(int cut_row, int cut_col, int number_symbols) {
//    int cut_index = cut_row * colums + cut_col;
//
//    memset(buffer.buffer_array, 0, buffer.size * sizeof(char));
//
//    for (int i = 0; i < number_symbols; i++) {
//        if (cut_index + i >= rows * colums) break;
//
//        if (i >= buffer.size) {
//            resize_buffer();
//        }
//
//        int text_row = (i + cut_index) / colums;
//        int text_col = (i + cut_index) % colums;
//
//        buffer.buffer_array[i] = text[text_row][text_col];
//    }
//
//    delete_symb(cut_row, cut_col, number_symbols);
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::INSERT, cut_row, cut_col, number_symbols, buffer.buffer_array);
//        while (!redo_stack.empty()) redo_stack.pop();
//        //memset(buffer.buffer_array, 0, buffer.size * sizeof(char));
//    }
//    
//}
//
//void TextEditor::paste(int paste_row, int paste_col) {
//    int paste_index = paste_row * colums + paste_col;
//
//    while (paste_index + strlen(buffer.buffer_array) > rows * colums || current_index + strlen(buffer.buffer_array) > rows * colums) {
//        resize_text();
//    }
//
//    insert(buffer.buffer_array, paste_row, paste_col);
//
//    int buf_size = strlen(buffer.buffer_array);
//
//    if (goes_to_undostack) {
//        push_undo(UndoAction::DELETE, paste_row, paste_col, buf_size);
//        while (!redo_stack.empty()) redo_stack.pop();
//    }
//}
//
//void TextEditor::copy(int copy_row, int copy_col, int number_symbols) { 
//    int copy_index = copy_row * colums + copy_col;
//
//    memset(buffer.buffer_array, 0, buffer.size * sizeof(char));
//
//    for (int i = 0; i < number_symbols; i++) {
//        if (copy_index + i >= current_index) break;
//
//        if (i >= buffer.size) {
//            resize_buffer();
//        }
//
//        int text_row = (i + copy_index) / colums;
//        int text_col = (i + copy_index) % colums;
//
//        if (text_row >= rows || text_col >= colums) break;
//
//        buffer.buffer_array[i] = text[text_row][text_col];
//    }
//    buffer.buffer_array[number_symbols] = '\0';
//}
//
//
//void TextEditor::push_undo(UndoAction::ActionType type, int row, int col, int length, const char* data) {
//    if (!goes_to_undostack) return;
//    
//    if (data != NULL) {
//        undo_stack.push(new UndoAction(type, row, col, length, data));
//    }
//    else {
//        undo_stack.push(new UndoAction(type, row, col, length));
//    }
//
//};
//
//void TextEditor::undo() {
//
//    if (!undo_stack.empty()) {
//        UndoAction* und_act = undo_stack.top();
//        undo_stack.pop();
//
//        redo_stack.push(new UndoAction(*und_act));
//
//        goes_to_undostack = false;
//
//        switch (und_act->type) {
//        case UndoAction::DELETE: {
//            delete_symb(und_act->row, und_act->column, und_act->length);
//            break;
//        }
//        case UndoAction::INSERT: {
//            insert(und_act->data, und_act->row, und_act->column);
//            break;
//        }
//        case UndoAction::DELETEINSERT: {
//            delete_symb(und_act->row, und_act->column, und_act->length);
//            insert(und_act->data, und_act->row, und_act->column);
//            break;
//        }
//          
//        }
//        delete und_act;
//        goes_to_undostack = true;
//    }
//    else
//    {
//        printf("No command to undo");
//    }
//
//};
//
//void TextEditor::redo() {
//    if (redo_stack.empty()) {
//        printf("No command to redo\n");
//        return;
//    }
//
//    UndoAction* act = redo_stack.top();
//    redo_stack.pop();
//
//    goes_to_undostack = false;
//
//    UndoAction* inverse = nullptr;
//
//    switch (act->type) {
//    case UndoAction::DELETE:
//        insert(act->data, act->row, act->column);
//        inverse = new UndoAction(UndoAction::DELETE, act->row, act->column, act->length);
//        break;
//    case UndoAction::INSERT:
//        delete_symb(act->row, act->column, act->length);
//        inverse = new UndoAction(UndoAction::INSERT, act->row, act->column, act->length, act->data);
//        break;
//    case UndoAction::DELETEINSERT:
//        delete_symb(act->row, act->column, act->length);
//        insert(act->data, act->row, act->column);
//        inverse = new UndoAction(*act); 
//        break;
//    }
//
//    if (inverse != nullptr) {
//        undo_stack.push(inverse);
//    }
//
//    delete act;
//    goes_to_undostack = true;
//};

//TextEditor::~TextEditor() {
//
//}