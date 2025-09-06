#include "bsttest.hpp"
#include "avltest.hpp"
#include "btreetest.hpp"
#include "sorttest.hpp"

// run all tests
int main(void)
{
    cout << "Testing BST" << endl;
    BSTTest::all();

    cout << "Testing AVL" << endl;
    AVLTest::all();

    cout << "Testing BTree" << endl;
    BTreeTest::all();

    cout << "Testing Sort Algorithms" << endl;
    SortTest::all();
}