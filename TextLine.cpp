#include "Headers/TextLine.h"
#include <iostream>
#include <cstddef>

TextLine::TextLine(const char* t) {
    textline = new char[strlen(t) + 1];
    strcpy(textline, t);
}

void TextLine::print() const{
    std::cout << "Text: " << textline << std::endl;
}

LineType TextLine::get_type() const {
    return LineType::TextLine;
}

std::vector<std::byte> TextLine::serialize() const {
    std::vector<std::byte> bytes;

    std::byte linetype_b = static_cast<std::byte>(LineType::TextLine);
    bytes.push_back(linetype_b);

    uint64_t len = strlen(textline) + 1;
    
    bytes.resize(sizeof(linetype_b) + sizeof(len) + len);
    memcpy(bytes.data() + sizeof(linetype_b), &len, sizeof(len));
    memcpy(bytes.data() + sizeof(linetype_b) + sizeof(len), textline, len);

    return bytes;
} 

TextLine* TextLine::deserialize(const std::byte* data, size_t size) {
    if (size < sizeof(uint64_t)) return nullptr;

    data++; 
    size--;

    uint64_t len = 0;
    memcpy(&len, data, sizeof(len));
    data += sizeof(len);
    size -= sizeof(len);

    if (size < len) return nullptr;

    return new TextLine(reinterpret_cast<const char*>(data));
}

TextLine::~TextLine() {
    delete[] textline;
}