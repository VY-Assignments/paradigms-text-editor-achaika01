#include <stdlib.h>
#pragma once

class TextEditor
{
private:
	struct Buffer {
		int size = 100;
		char* buffer_array;

		Buffer() {
			buffer_array = (char*)malloc(size * sizeof(char));
		}

		~Buffer() {
			free(buffer_array);
		}
	};
	Buffer buffer;
	void resize_text();
	void resize_buffer();
	int get_free_space_in_text();
	int rows = 10;							
	int colums = 10;				
	int start_from_row = 0;	
	int current_index = 0;			
	char** text = nullptr;

public:
	TextEditor();
	void command(int input);
	void print();
	void start_new_line();
	void save_to_the_file(char* file_name);
	void load_from_file(char* file_name);
	void search(char* user_input);
	void insert(char* user_input, int insert_row, int insert_col);
	void insert_with_replacement(char* user_input, int insert_row, int insert_col);
	void append_symbols_end();
	void delete_symb(int delete_row, int delete_col, int number_symbols);
	void cut(int cut_row, int cut_col, int number_symbols);
	~TextEditor();
};
