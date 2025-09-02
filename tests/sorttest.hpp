#ifndef __SORTTEST_HPP__
#define __SORTTEST_HPP__

#include "../sort.hpp"

#include <vector>
#include <iostream>
using namespace std;

namespace SortTest
{
	vector<int> get_test_data(void)
	{
		return {5, 2, 5, 3, 2, 5, 3, 1, 4, 3};
	}

	vector<int> get_target_data(void)
	{
		return {1, 2, 2, 3, 3, 3, 4, 5, 5, 5};
	}

	void test_selsort(void)
	{
		vector<int> X = get_test_data();
		vector<int> Y = get_target_data();

		selsort<int>(X.data(), X.size());

		for (size_t i = 0; i < X.size(); i++)
		{
			assert(X[i] == Y[i]);
		}
	}

	void all()
	{
		test_selsort();
	}
}

#endif