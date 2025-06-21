#pragma once
#include <string>
#include "Line.h"

class ContactLine : public Line {
	std::string fullname;
	std::string email;
public:
	ContactLine(const std::string& f, const std::string e) : fullname(f), email(e) {}

	void print() const override;
};
