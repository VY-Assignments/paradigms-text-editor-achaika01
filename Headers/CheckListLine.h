#pragma once
#include <string>
#include "Line.h"
class CheckListLine : public Line {
	std::string item;
	bool checked;
public:
	CheckListLine(const std::string& i, bool c) : item(i), checked(c) {}

	void print() const override;
};
