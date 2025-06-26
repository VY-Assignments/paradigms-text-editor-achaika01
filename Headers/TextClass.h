#pragma once
#include <vector> 
#include "Line.h" 

class TextClass {
	std::vector<Line*> text;

public:
	TextClass() = default;

	TextClass(const TextClass&) = delete;
	TextClass& operator=(const TextClass&) = delete;

	void add_line(int line_type);
	size_t size() const;
	Line* get_line(size_t index) const;
	void clear();
	void add_line(Line*);

	void printAll() const;
	~TextClass() {
		clear();
	}
};
