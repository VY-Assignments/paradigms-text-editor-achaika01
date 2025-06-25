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

CheckListLine* CheckListLine::deserialize(const std::byte* data, size_t size) {

    const size_t type_size = sizeof(byte);
    const size_t bool_size = sizeof(byte);
    const size_t len_size = sizeof(uint64_t);

    if (size < type_size + bool_size + len_size)
        return nullptr;

    data++;
    size--;

    bool checked = static_cast<bool>(*data);
    data++;
    size--;

    uint64_t len = 0;
    memcpy(&len, data, sizeof(len));
    data += sizeof(len);
    size -= sizeof(len);

    if (size < len) return nullptr;

    string item(reinterpret_cast<const char*>(data), len - 1);

    return new CheckListLine(item, checked);
}
