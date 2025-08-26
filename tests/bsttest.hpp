#ifndef __BSTTEST_HPP__
#define __BSTTEST_HPP__

#include "../bst.hpp"
#include <cassert>

namespace BSTTest
{
	/// @brief Generate some test data
	/// @return Some test data.
	BST<int> *get_test_data()
	{
		BST<int> *bst = new BST<int>();

		bst->insert(5);
		bst->insert(3);
		bst->insert(6);
		bst->insert(4);
		bst->insert(2);

		return bst;
	}

	/// @brief Test the search method
	void test_search()
	{
		BST<int> *bst = get_test_data();

		assert(bst->contains(5));
		assert(bst->contains(3));
		assert(bst->contains(6));
		assert(bst->contains(4));
		assert(bst->contains(2));

		assert(!bst->contains(1));
		assert(!bst->contains(7));

		delete bst;
	}

	/// @brief Run all the tests
	void all()
	{
		test_search();
	}
}

#endif