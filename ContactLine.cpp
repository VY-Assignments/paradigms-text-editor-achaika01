#include "Headers/ContactLine.h"
#include <iostream>
using namespace std;

void ContactLine::print() const {
	cout << "Contact - " << fullname << ", E-mail: " << email << endl;
}

LineType ContactLine::get_type() const {
	return LineType::ContactLine;
}

vector<byte> ContactLine::serialize() const {
	vector<byte> bytes;
	uint64_t start_from = 0;

	byte linetype_b = static_cast<byte>(LineType::ContactLine);
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
