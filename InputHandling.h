#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H
#include <iostream>
using namespace std;

class InvalidInput
{
public:
	InvalidInput(const char* in_ptr): msg_ptr(in_ptr) {}
	const char* const msg_ptr;
private:
	InvalidInput();
};

#endif
