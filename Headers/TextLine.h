#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Line.h"
#include <cstring> 
#include <vector>
#include <cstddef>

class TextLine : public Line {
	char* textline;
public:
	TextLine(const char* t);

	void print() const override;

	std::vector<std::byte> serialize() const override;
	static TextLine* deserialize(const std::byte* data, size_t size);

	LineType get_type() const override;

	~TextLine();
};
