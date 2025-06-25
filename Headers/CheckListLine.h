#pragma once
#include <string>
#include <vector>
#include "CheckListLine.h"
#include "Line.h"

class CheckListLine : public Line {
	std::string item;
	bool checked;
public:
	CheckListLine(const std::string& i, bool c) : item(i), checked(c) {}

	void print() const override;

	std::vector<std::byte> serialize() const override;
	static CheckListLine* deserialize(const std::byte* data, size_t size);

	LineType get_type() const override;

	~CheckListLine() {};
};
