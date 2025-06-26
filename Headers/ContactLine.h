#pragma once
#include <string>
#include <vector>
#include "Line.h"
#include <cstddef>

class ContactLine : public Line {
	std::string fullname;
	std::string email;
public:
	ContactLine(const std::string& f, const std::string e) : fullname(f), email(e) {}

	void print() const override;

	std::vector<std::byte> serialize() const override;
	static ContactLine* deserialize(const std::byte* data, size_t size);

	LineType get_type() const override;

	~ContactLine() {};
};
