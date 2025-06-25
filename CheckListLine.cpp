#include "Headers/CheckListLine.h"
#include <iostream>
using namespace std;

void CheckListLine::print() const {
	cout << "[ " << (checked ? "x" : " ") << " ] " << item << std::endl;
}

LineType CheckListLine::get_type() const {
	return LineType::CheckListLine;
}

vector<byte> CheckListLine::serialize() const {
    vector<byte> bytes;

    byte linetype_b = static_cast<byte>(LineType::CheckListLine);
    bytes.push_back(linetype_b);

    byte checked_b = static_cast<byte>(checked ? 1 : 0);
    bytes.push_back(checked_b);
    uint64_t len = item.length() + 1;

    bytes.resize(sizeof(linetype_b) + sizeof(checked_b) + sizeof(len) + len);
    memcpy(bytes.data() + sizeof(linetype_b) + sizeof(checked_b), &len, sizeof(len));
    memcpy(bytes.data() + sizeof(linetype_b) + sizeof(checked_b) + sizeof(len), item.c_str(), len);

    return bytes;
}
