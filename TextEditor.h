
#pragma once

class TextEditor
{
private:
	void resize_text();
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
};
