#ifndef __BTREETEST_HPP__
#define __BTREETEST_HPP__

#include "../btree.hpp"

namespace BTreeTest
{
	void it_compiles()
	{
		BTree<int, 3> *btree = new BTree<int, 3>();

		delete btree;
	}

	void all()
	{
		it_compiles();
	}
}

#endif