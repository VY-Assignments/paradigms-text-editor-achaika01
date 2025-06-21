#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Line.h"
#include <cstring> 

class TextLine : public Line {
	char* textline;
public:
	TextLine(const char* t) {
		textline = new char[strlen(t) + 1];
		strcpy(textline, t);
	}
	void print() const override;

};
