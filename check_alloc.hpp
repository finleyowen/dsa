#ifndef CHECK_ALLOC

#include <iostream>
#include <cstddef>
using namespace std;

#define CHECK_ALLOC(ptr)                             \
	if (ptr == nullptr)                              \
	{                                                \
		cout << "Memory allocation failed!" << endl; \
		exit(EXIT_FAILURE);                          \
	}

#endif