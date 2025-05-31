#include <stdlib.h>
#include <stack>
#pragma once
using namespace std;

class TextEditor
{
private:
	bool goes_to_undostack = true;

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

	struct UndoAction {
		enum ActionType {DELETE, INSERT, DELETEINSERT} type;
		int row;
		int column;
		int length;
		char* data;

		UndoAction(ActionType t, int r, int c, int l, const char* d) {
			row = r;
			column = c;
			length = l;
			type = t;

			if (l != 0 && d != nullptr) {
				data = new char[length + 1];
				strncpy(data, d, length);
				data[length] = '\0';
			}
			else {
				data = nullptr;
			}
			
		}

		UndoAction(ActionType t, int r, int c, int l) {
			row = r;
			column = c;
			length = l;
			type = t;
			data = nullptr;
		}

		~UndoAction() {
			if (data != nullptr) {
				delete[] data;
			}
		}

	};

	stack<UndoAction*> undo_stack;

	Buffer buffer;
	void resize_text();
	void resize_buffer();
	int get_free_space_in_text();
	int rows = 10;							
	int colums = 10;				
	int start_from_row = 0;	
	int current_index = 0;			
	char** text = nullptr;
	void push_undo(UndoAction::ActionType type, int row, int col, int length, const char* data = NULL);

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
	void paste(int paste_row, int paste_col);
	void copy(int copy_row, int copy_col, int number_symbols);
	void undo();
	~TextEditor();
};
