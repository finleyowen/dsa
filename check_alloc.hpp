#ifndef CHECK_ALLOC

#include <iostream> // for cout
#include <cstddef>	// for exit, EXIT_FAILURE
using namespace std;

// check `new` was successful
#define CHECK_ALLOC(ptr)                             \
	if (ptr == nullptr)                              \
	{                                                \
		cout << "Memory allocation failed!" << endl; \
		exit(EXIT_FAILURE);                          \
	}

#endif