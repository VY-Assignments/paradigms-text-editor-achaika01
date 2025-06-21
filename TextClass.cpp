#include <vector>
#include <string>
#include <iostream>
#include "Headers/Line.h"
#include "Headers/CheckListLine.h"
#include "Headers/TextClass.h"
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
		break;
	case 3:
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
	}
}