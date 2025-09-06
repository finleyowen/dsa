#ifndef __SORTTEST_HPP__
#define __SORTTEST_HPP__

#include "../sort.hpp"
#include <vector>
#include <cassert>
using namespace std;

namespace SortTest
{

    vector<int> get_test_data()
    {
        return {4, 2, 3, 6, 2, 4, 1, 6};
    }

    vector<int> get_sorted_test_data()
    {
        return {1, 2, 2, 3, 4, 4, 6, 6};
    }

    void test_inplace_sort(void (*sortfn)(int[], size_t))
    {
        vector<int> x = get_test_data();
        vector<int> y = get_sorted_test_data();

        sortfn(x.data(), x.size());

        for (size_t i = 0; i < x.size(); i++)
        {
            assert(x[i] == y[i]);
        }
    }

    void test_selection_sort()
    {
        test_inplace_sort(selection_sort);
    }

    void test_quick_sort()
    {
        test_inplace_sort(quick_sort);
    }

    void all()
    {
        cout << "Testing Selection Sort" << endl;
        test_selection_sort();

        cout << "Testing Quick Sort" << endl;
        test_quick_sort();
    }

}

#endif