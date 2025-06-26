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

void TextClass::us_command(int com) {
	switch (com) {
	case 1:
		int line_type;
		do {
			printf("Choose type of line: \n1.Check list line\n2.Text line\n3.Contact line\nEnter number: ");
			std::cin >> line_type;
			this->add_line(line_type);
		} while (line_type != 1 && line_type != 2 && line_type != 3);
		break;
	case 2:
		this->printAll();
		break;
	case 3:
		std::cout << "not implemented" << std::endl;
	}
}