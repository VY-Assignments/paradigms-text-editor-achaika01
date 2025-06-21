#include "Headers/ContactLine.h"
#include <iostream>
using namespace std;

void ContactLine::print() const {
	cout << "Contact - " << fullname << ", E-mail: " << email << endl;
}