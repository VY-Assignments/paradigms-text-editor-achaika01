#pragma once

class TextClass {
	std::vector<Line*> text;

public:
	void add_line(int line_type);
	void printAll() const;
	void us_command(int c);
	~TextClass() {
		for (size_t i = 0; i < text.size(); ++i) {
			delete text[i];
		}
	}
};
