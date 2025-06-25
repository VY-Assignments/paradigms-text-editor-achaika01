#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <iostream>
#include "Headers/Line.h"
#include "Headers/CheckListLine.h"
#include "Headers/TextLine.h"
#include "Headers/TextClass.h"
#include "Headers/ContactLine.h"
using namespace std;

void TextClass::add_line(int line_type) {
	switch (line_type) {
	case 1: {
		int checked;
		cout << "Enter 1 if checked, 0 if not" << endl;
		cin >> checked;
		if (checked != 0 && checked != 1) {
			cout << "wrong number" << endl;
			break;
		}
		string input;
		cout << "Enter text: ";
		cin >> input;
		text.push_back(new CheckListLine(input, checked));
		break;
	}
	case 2:
	{
		string input;
		cout << "Enter text: ";
		cin >> input;

		char* new_text_line = (char*)malloc((input.length() + 1) * sizeof(char));
		strcpy(new_text_line, input.c_str());
		text.push_back(new TextLine(new_text_line));
		break;
	}
	case 3:
		string fullname;
		string phone_number;
		cout << "Enter fullname: " << endl;
		cin.ignore();
		getline(cin, fullname);

		cout << "Enter number: " << endl;
		getline(cin, phone_number);

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
			cin >> line_type;
			this->add_line(line_type);
		} while (line_type != 1 && line_type != 2 && line_type != 3);
		break;
	case 2:
		this->printAll();
		break;
	case 3:
		cout << "not implemented" << endl;
	}
}