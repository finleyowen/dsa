#ifndef __BTREETEST_HPP__
#define __BTREETEST_HPP__

#include "../btree.hpp"

namespace BTreeTest
{
	void it_compiles(void)
	{
		BTree<int, 3> *tree = new BTree<int, 3>();

		delete tree;
	}

	void all()
	{
		it_compiles();
	}
}

#endif