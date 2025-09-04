# Data Structures and Algorithms

A collection of reusable Algorithms and Data Structures written as header-only class templates in C++.

## Get started (on Linux or WSL)

To compile the test programs, ensure you have a C++ compiler installed and, if it isn't `g++`, edit the value of `CC` in `tests/Makefile`. 

Then, run:
```
cd path/to/dsa/tests
```

To move into the test directory, and:
```
mkdir -p tests/bin
```

To create the `tests/bin` subdirectory if it doesn't exist. Then:
```
make
```

To compile the tests and finally:
```
bin/test
```

To execute them.  

Most of the header files from this repository should be able to be moved around and imported into your application freely. However, there are notable exceptions listed in the [Dependencies](#dependencies) section.

## Modules

### `bst.hpp`

Define the `BSTNode` and `BST` classes and their methods.

### `avl.hpp`

Defines the `AVL` class and its methods.

## Dependencies

The following dependent relationships exist between the modules in this repository.

- `avl.hpp` depends on `bst.hpp`.