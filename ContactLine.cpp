#include "Headers/ContactLine.h"
#include <iostream>
#include <vector>
#include <cstddef>

void ContactLine::print() const {
	std::cout << "Contact - " << fullname << ", E-mail: " << email << std::endl;
}

LineType ContactLine::get_type() const {
	return LineType::ContactLine;
}

std::vector<std::byte> ContactLine::serialize() const {
	std::vector<std::byte> bytes;
	uint64_t start_from = 0;

	std::byte linetype_b = static_cast<std::byte>(LineType::ContactLine);
	bytes.push_back(linetype_b);
	start_from += sizeof(linetype_b);

	uint64_t len_name = fullname.length() + 1;
	uint64_t len_email = email.length() + 1;

	bytes.resize(sizeof(linetype_b) + sizeof(len_name) + len_name + sizeof(len_email) + len_email);


	memcpy(bytes.data() + start_from, &len_name, sizeof(len_name));
	start_from += sizeof(len_name);
	memcpy(bytes.data() + start_from, fullname.c_str(), len_name);
	start_from += len_name;

	memcpy(bytes.data() + start_from, &len_email, sizeof(len_email));
	start_from += sizeof(len_email);
	memcpy(bytes.data() + start_from, email.c_str(), len_email);
	start_from += len_email;

	return bytes;
}

ContactLine* ContactLine::deserialize(const std::byte* data, size_t size) {
	const size_t type_size = sizeof(std::byte);
	const size_t len_size = sizeof(uint64_t);

	if (size < type_size + len_size) return nullptr;

	data++;
	size--;


	uint64_t len_name = 0;
	memcpy(&len_name, data, sizeof(len_name));
	data += sizeof(len_name);
	size -= sizeof(len_name);

	if (size < len_name) return nullptr;

	std::string name(reinterpret_cast<const char*>(data), len_name - 1);
	data += len_name;
	size -= len_name;

	uint64_t len_email = 0;
	memcpy(&len_email, data, sizeof(len_email));
	data += sizeof(len_email);
	size -= sizeof(len_email);

	if (size < len_email) return nullptr;

	std::string email(reinterpret_cast<const char*>(data), len_email - 1);

	return new ContactLine(name, email);
}
