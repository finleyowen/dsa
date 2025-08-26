#ifndef __AVLTEST_HPP__
#define __AVLTEST_HPP__

#include "../avl.hpp"
#include <cassert>

namespace AVLTest
{
	/// @brief Generate some test data
	/// @return Some test data.
	AVL<int> *get_test_data()
	{
		AVL<int> *avl = new AVL<int>();

		avl->insert(5);
		avl->insert(3);
		avl->insert(6);
		avl->insert(4);
		avl->insert(2);

		return avl;
	}

	/// @brief Test the `search` method.
	void test_search()
	{
		AVL<int> *avl = get_test_data();

		assert(avl->contains(5));
		assert(avl->contains(3));
		assert(avl->contains(6));
		assert(avl->contains(4));
		assert(avl->contains(2));

		assert(!avl->contains(1));
		assert(!avl->contains(7));

		delete avl;
	}

	/// @brief Test the `avl_balance` method.
	void test_balance()
	{
		AVL<int> *avl = new AVL<int>();
		CHECK_ALLOC(avl);

		avl->insert(1);
		avl->insert(2);
		avl->insert(3);
		avl->insert(4);
		avl->insert(5);

		int bf = avl->get_root()->avl_balance_factor();
		assert(-1 < bf && bf < 1);

		delete avl;
	}

	/// @brief Run all the tests
	void all()
	{
		test_search();
		test_balance();
	}
}

#endif