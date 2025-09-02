#include "bsttest.hpp"
#include "avltest.hpp"
#include "sorttest.hpp"

// run all tests
int main(void)
{
	cout << "Testing BST" << endl;
	BSTTest::all();

	cout << "Testing AVL" << endl;
	AVLTest::all();

	cout << "Testing sort algs" << endl;
	SortTest::all();
}