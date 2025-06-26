#pragma once
#include "TextClass.h"

class CommandLineInterface
{
	TextClass text;

	std::vector<TextClass> tabs;
	size_t active_tab = 0;

public:

	CommandLineInterface();

	void new_tab();

	void switch_tab(size_t index);

	void run();
	void us_command(int com);
	void savefile(const std::string& filename) const;
	void loadfile(const std::string& filename);
	void encryptfile(const std::string& input_filename, const std::string& output_filename, int key) const;
	void decryptfile(const std::string& input_filename, const std::string& output_filename, int key) const;

	~CommandLineInterface() {};

};