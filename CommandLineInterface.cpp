#define NOMINMAX
#include <iostream>
#include <fstream>
#include <string>
#include "Headers/CommandLineInterface.h"
#include "Headers/CaesarCipher.h"

CommandLineInterface::CommandLineInterface() {
	tabs.emplace_back(std::make_unique<TextClass>());
}

void CommandLineInterface::new_tab() {
	tabs.emplace_back(std::make_unique<TextClass>());
	active_tab = tabs.size() - 1;
	std::cout << "Added new tab. Current tab: " << active_tab << std::endl;
}

void CommandLineInterface::switch_tab(size_t index) {
	if (index < tabs.size()) {
		active_tab = index;
		std::cout << "Changed tab to tab " << index << std::endl;
	}
	else {
		std::cout << "No tab with index " << index << std::endl;
	}
}

void CommandLineInterface::us_command(int com) {
	switch (com) {
	case 1:
	{
		int line_type;
		do {
			std::cout << "Choose type of line:\n1. Check list line\n2. Text line\n3. Contact line\nEnter number: ";
			std::cin >> line_type;
		} while (line_type != 1 && line_type != 2 && line_type != 3);
		tabs[active_tab]->add_line(line_type);
		break;
	}
	case 2:
		tabs[active_tab]->printAll();
		break;
	case 3:
	{
		std::string filename_input;
		std::string filename_output;
		int key;

		std::cout << "Enter filename input: ";
		std::cin >> filename_input;

		std::cout << "Enter filename output: ";
		std::cin >> filename_output;

		std::cout << "Enter key: ";
		std::cin >> key;

		this->encryptfile(filename_input, filename_output, key);
		break;
	}
	case 4:
	{
		std::string filename_input1;
		std::string filename_output1;
		int key2;

		std::cout << "Enter filename input: ";
		std::cin >> filename_input1;

		std::cout << "Enter filename output: ";
		std::cin >> filename_output1;

		std::cout << "Enter key: ";
		std::cin >> key2;

		this->decryptfile(filename_input1, filename_output1, key2);
		break;
	}
	case 5:
	{
		std::string filename;
		std::cout << "Enter filename: ";
		std::cin >> filename;
		this->savefile(filename);
		break;
	}
	case 6:
	{
		std::string filename;
		std::cout << "Enter filename: ";
		std::cin >> filename;
		this->loadfile(filename);
		break;
	}
	case 7:
		new_tab();
		break;
	case 8:
	{
		size_t index;
		std::cout << "Enter tab index to switch to: ";
		std::cin >> index;
		switch_tab(index);
		break;
	}
	}
}

void CommandLineInterface::run() {
	int command;
	do {
		std::cout << "Text Editor (tab " << active_tab << ")" << std::endl
			<< "1. Add line\n"
			<< "2. Print all lines\n"
			<< "3. Encrypt file\n"
			<< "4. Decrypt file\n"
			<< "5. Save to file\n"
			<< "6. Load from file\n"
			<< "7. New tab\n"
			<< "8. Switch tab\n"
			<< "15. Exit\n"
			<< "Enter command: ";
		std::cin >> command;
		if (command != 15) us_command(command);
	} while (command != 15);
}

void CommandLineInterface::savefile(const std::string& filename) const {
	std::ofstream out(filename, std::ios::binary);
	if (!out.is_open()) {
		std::cout << "Cannot open file for writing\n";
		return;
	}
	const TextClass& tab = *tabs[active_tab];

	uint64_t count = tab.size();
	out.write(reinterpret_cast<const char*>(&count), sizeof(count));

	for (size_t i = 0; i < count; ++i) {
		Line* line = tab.get_line(i);
		if (!line) continue;

		std::vector<std::byte> serialized = line->serialize();

		uint64_t size = serialized.size();
		out.write(reinterpret_cast<const char*>(&size), sizeof(size));
		out.write(reinterpret_cast<const char*>(serialized.data()), size);
	}

	out.close();
}

void CommandLineInterface::loadfile(const std::string& filename) {
	TextClass& tab = *tabs[active_tab];
	tab.clear();

	std::ifstream in(filename, std::ios::binary);
	if (!in.is_open()) {
		std::cout << "Cannot open file for reading\n";
		return;
	}

	uint64_t count;
	in.read(reinterpret_cast<char*>(&count), sizeof(count));

	for (uint64_t i = 0; i < count; ++i) {
		uint64_t size;
		in.read(reinterpret_cast<char*>(&size), sizeof(size));

		std::vector<std::byte> buffer(size);
		in.read(reinterpret_cast<char*>(buffer.data()), size);

		Line* line = Line::deserialize(buffer);
		if (line) {
			tab.add_line(line);
		}
	}

	in.close();
}

void CommandLineInterface::encryptfile(const std::string& input_filename, const std::string& output_filename, int key) const {
	std::ifstream in(input_filename, std::ios::binary);
	if (!in.is_open()) {
		std::cout << "Cannot open input file\n";
		return;
	}
	std::vector<char> temp_buffer((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	in.close();

	std::vector<std::byte> buffer;
	buffer.reserve(temp_buffer.size());
	for (char c : temp_buffer) {
		buffer.push_back(static_cast<std::byte>(c));
	}

	CaesarCipher cipher;
	std::vector<std::byte> encrypted = cipher.encrypt(buffer, key);

	std::ofstream out(output_filename, std::ios::binary);
	if (!out.is_open()) {
		std::cout << "Cannot open output file\n";
		return;
	}

	out.write(reinterpret_cast<const char*>(encrypted.data()), encrypted.size());
	out.close();
}

void CommandLineInterface::decryptfile(const std::string& input_filename, const std::string& output_filename, int key) const {
	std::ifstream in(input_filename, std::ios::binary);
	if (!in.is_open()) {
		std::cout << "Cannot open encrypted input file\n";
		return;
	}

	std::vector<char> temp_buffer((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	in.close();

	std::vector<std::byte> buffer;
	buffer.reserve(temp_buffer.size());
	for (char c : temp_buffer) {
		buffer.push_back(static_cast<std::byte>(c));
	}

	CaesarCipher cipher;
	std::vector<std::byte> decrypted = cipher.decrypt(buffer, key);

	std::ofstream out(output_filename, std::ios::binary);
	if (!out.is_open()) {
		std::cout << "Cannot open output file\n";
		return;
	}

	out.write(reinterpret_cast<const char*>(decrypted.data()), decrypted.size());
	out.close();
}
