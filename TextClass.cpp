#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include "Headers/Line.h"
#include "Headers/CheckListLine.h"
#include "Headers/TextLine.h"
#include "Headers/TextClass.h"
#include "Headers/ContactLine.h"

void TextClass::add_line(int line_type) {
	switch (line_type) {
	case 1: {
		int checked;
		std::cout << "Enter 1 if checked, 0 if not" << std::endl;
		std::cin >> checked;
		if (checked != 0 && checked != 1) {
			std::cout << "wrong number" << std::endl;
			break;
		}
		std::string input;
		std::cout << "Enter text: ";
		std::cin >> input;
		text.push_back(new CheckListLine(input, checked));
		break;
	}
	case 2:
	{
		std::string input;
		std::cout << "Enter text: ";
		std::cin >> input;

		char* new_text_line = (char*)malloc((input.length() + 1) * sizeof(char));
		strcpy(new_text_line, input.c_str());
		text.push_back(new TextLine(new_text_line));
		break;
	}
	case 3:
		std::string fullname;
		std::string phone_number;
		std::cout << "Enter fullname: " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, fullname);

		std::cout << "Enter number: " << std::endl;
		std::getline(std::cin, phone_number);

		text.push_back(new ContactLine(fullname, phone_number));
		break;
	}
}

void TextClass::printAll() const {
	for (size_t i = 0; i < text.size(); ++i) {
		text[i]->print();
	}
}

size_t TextClass::size() const {
	return text.size();
}

Line* TextClass::get_line(size_t index) const {
	if (index < text.size())
		return text[index];
	return nullptr;
}

void TextClass::add_line(Line* line) {
	text.push_back(line);
}

void TextClass::clear() {
	for (Line* line : text) {
		delete line;
	}
	text.clear();
}