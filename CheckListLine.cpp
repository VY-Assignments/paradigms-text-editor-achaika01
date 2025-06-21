#include "Headers/CheckListLine.h"
#include <iostream>
using namespace std;

void CheckListLine::print() const {
	cout << "[ " << (checked ? "x" : " ") << " ] " << item << std::endl;
}