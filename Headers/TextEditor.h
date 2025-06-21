#include <stdlib.h>
#include <stack>
#include <vector>
#include "Line.h"
#pragma once
using namespace std;

class TextEditor
{
private:
	vector<Line*> text;

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

		UndoAction(const UndoAction& other) {
			type = other.type;
			row = other.row;
			column = other.column;
			length = other.length;

			if (other.data != nullptr) {
				data = new char[length + 1];
				strcpy(data, other.data);
			}
			else {
				data = nullptr;
			}
		}

		~UndoAction() {
			if (data != nullptr) {
				delete[] data;
			}
		}

	};

	stack<UndoAction*> undo_stack;

	stack<UndoAction*> redo_stack;

	Buffer buffer;
	void resize_buffer();
	int rows = 10;							
	//int colums = 10;				
	int start_from_line = 0;	
	int current_index = 0;			
	void push_undo(UndoAction::ActionType type, int row, int col, int length, const char* data = NULL);
	void add_text_line();

public:
	TextEditor();
	void command(int input);
	void start_new_line();
	void add_line(int line_type);
	~TextEditor();
};


