#ifndef __SORT_HPP__
#define __SORT_HPP__

#include <cstddef>
using namespace std;

template <typename T>
void selection_sort(T A[], size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (A[i] > A[j])
            {
                T tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

template <typename T>
void insertion_sort(T A[], size_t n)
{
    size_t i, j, insert_idx;
    T val;

    for (i = 0; i < n; i++)
    {
        insert_idx = i;
        val = A[i];

        for (j = i - 1; j >= 0; j++)
        {
            if (A[j] > A[i])
            {
                A[j + 1] = A[j];
                insert_idx = j;
            }
            else
            {
                break;
            }
        }
        A[insert_idx] = val;
    }
}

template <typename T>
void quick_sort(T A[], size_t n)
{
    // an empty array, or one with one element, is already
    // sorted
    if (n <= 1)
        return;

    // create the subarrays
    T *left = new T[n],
      *right = new T[n];

    // track the lengths of the subarrays
    size_t n_left = 0, n_right = 0;

    // define a pivot
    size_t pivot_idx = 0;
    T pivot = A[pivot_idx];

    // partition the array into subarrays
    for (size_t i = 0; i < n; i++)
    {
        // skip the pivot
        if (i == pivot_idx)
            continue;

        // insert into a subarray
        else if (A[i] > pivot)
        {
            right[n_right++] = A[i];
        }
        else
        {
            left[n_left++] = A[i];
        }
    }

    // recursively sort the two halves of the array
    quick_sort<T>(left, n_left);
    quick_sort<T>(right, n_right);

    // copy the contents from the two subarrays back into
    // the original array

    // copy the left subarray
    for (size_t i = 0; i < n_left; i++)
    {
        A[i] = left[i];
    }

    // copy the pivot itself back in
    A[n_left] = pivot;

    // copy the right subarray back in
    for (size_t i = 0; i < n_right; i++)
    {
        A[n_left + 1 + i] = right[i];
    }

    // free the memory occupied by the two subarrays
    delete[] left;
    delete[] right;
}

template <typename T>
T *merge_sort(T A[], size_t n) 
{
    if(n <= 1) {
        // already sorted; copy the element if there is one and return an array 
        T *sorted = new T[n];
        if(n > 0) {
            sorted[0] = A[0];
        }
        return sorted;
    }

    size_t n_left = n / 2,
        n_right = n - n_left;

    T *left = merge_sort(A, n_left);
    T *right = merge_sort(A + n_left, n_right);
    
    T *sorted = new T[n];

    size_t i = 0, j = 0;

    while (i < n_left && j < n_right) {
        if(left[i] < right[j]) {
            sorted[i + j] = left[i];
            i ++;
        } else {
            sorted[i + j] = right[j];
            j ++;
        }
    }

    while(i < n_left) {
        sorted[i + j] = left[i];
        i ++;
    }

    
    while(j < n_right) {
        sorted[i + j] = right[j];
        j ++;
    }

    delete[] left;
    delete[] right;

    return sorted;
}
#endif