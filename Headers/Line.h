#pragma once
#include <bit>
#include <cstdint>

enum class LineType : uint8_t {
	TextLine = 1,
	CheckListLine = 2,
	ContactLine = 3
};

class Line {
public:
	virtual void print() const = 0;
	virtual std::vector<std::byte> serialize() const = 0;
	static Line* deserialize(const std::vector<std::byte>& data);
	virtual LineType get_type() const = 0;
	virtual ~Line() {}
};